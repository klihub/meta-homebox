# This class creates an image which is booted using syslinux.
#
# The image has an MSDOS partition table and comes with 3 partitions:
#  - a VFAT boot partition
#  - a primary rootfs partition
#  - a secondary rootfs partition

# This is the default WIC kickstart file we use. 
WKS_FILE ?= "refkit-syslinux.wks.in"

# These are the default partition sizes.
REFKIT_VFAT_MB ?= "64"
REFKIT_IMAGE_SIZE ?= "--fixed-size 1024M"

# Produce WIC debug output.
WIC_CREATE_EXTRA_ARGS += " -D"

# Do not use the redundant '.rootfs' suffix.
IMAGE_NAME_SUFFIX = ""

inherit syslinux

SYSLINUX_CFG = "${S}/syslinux.cfg"
SYSLINUX_TIMEOUT = "500"
SYSLINUX_PROMPT  = "1"
SYSLINUX_SPLASH  = ""

SYSLINUX_DEFAULT_CONSOLE = "console=tty0"
SYSLINUX_SERIAL_TTY      = "console=ttyS0,115200"
SYSLINUX_SERIAL          = "0 115200"

SYSLINUX_ALLOWOPTIONS = "1"
AUTO_SYSLINUXMENU     = "1"

INITRD = "${INITRD_IMAGE}"
LABELS = "primary secondary"

python do_syslinux_config() {
    bb.build.exec_func('build_syslinux_cfg', d)
}

do_syslinux_deploy () {
    syslinux_populate ${IMAGE_ROOTFS} /boot syslinux.cfg
    install -m 0444 ${STAGING_DATADIR}/syslinux/ldlinux.sys \
        ${IMAGE_ROOTFS}${SYSLINUXDIR}/ldlinux.sys
    cp ${IMAGE_ROOTFS}/boot/bzImage ${IMAGE_ROOTFS}/boot/vmlinuz
    cp ${DEPLOY_DIR_IMAGE}/${INITRD_IMAGE}-${MACHINE}.cpio.gz ${IMAGE_ROOTFS}/boot/initrd
}

# If we're not building an initramfs, hook us in to the build tasks.
python () {
    image_fstypes = d.getVar('IMAGE_FSTYPES', True)
    initramfs_fstypes = d.getVar('INITRAMFS_FSTYPES', True)

    if initramfs_fstypes not in image_fstypes:
        bb.build.addtask('syslinux_config', 'do_image', 'do_rootfs', d)
        bb.build.addtask('syslinux_deploy', 'do_image', 'do_syslinux_config', d)
}
