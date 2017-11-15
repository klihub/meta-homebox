SUMMARY = "Home Box initramfs image"
DESCRIPTION = "Finds the rootfs by filesystem label."

PACKAGE_INSTALL = " \
    busybox \
    base-passwd \
    ${ROOTFS_BOOTSTRAP_INSTALL} \
    ${FEATURE_INSTALL} \
    initramfs-module-debug \
    initramfs-module-udev \
"

# Do not build by default.
EXCLUDE_FROM_WORLD = "1"

# Do not pollute the initrd image with rootfs features
IMAGE_FEATURES = ""
IMAGE_LINGUAS = ""

LICENSE = "MIT"

IMAGE_FSTYPES = "${INITRAMFS_FSTYPES}"
inherit core-image

BAD_RECOMMENDATIONS += "busybox-syslog"
