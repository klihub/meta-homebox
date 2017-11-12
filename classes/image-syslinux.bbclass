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
REFKIT_IMAGE_SIZE ?= "--fixed-size 512M"

# Produce WIC debug output.
WIC_CREATE_EXTRA_ARGS += " -D"

# Do not use the redundant '.rootfs' suffix.
IMAGE_NAME_SUFFIX = ""

SYSLINUX_TIMEOUT = "50"
SYSLINUX_PROMPT  = "1"
SYSLINUX_SERIAL_TTY = "console=ttyS0,38400"
SYSLINUX_SERIAL     = "0 38400"
SYSLINUX_ALLOWOPTIONS = "1"
INITRD = "${@('${DEPLOY_DIR_IMAGE}/' + \
    d.getVar('INITRD_IMAGE', expand=True) + \
        '-${MACHINE}.cpio.gz') \
    if d.getVar('INITRD_IMAGE', True) else ''}"
