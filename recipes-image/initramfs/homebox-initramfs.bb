SUMMARY = "Home Box initramfs image"
DESCRIPTION = "Finds the rootfs by filesystem label."
LICENSE = "MIT"

# Do not build by default.
EXCLUDE_FROM_WORLD = "1"

PACKAGE_INSTALL = " \
    busybox \
    base-passwd \
    ${ROOTFS_BOOTSTRAP_INSTALL} \
    ${FEATURE_INSTALL} \
    initramfs-module-debug \
    initramfs-module-udev \
"

# Do not pollute the initrd image with rootfs features.
IMAGE_FEATURES = ""
IMAGE_LINGUAS = ""

# Set up our initrd-specific features instead.
IMAGE_FEATURES[validitems] = " \
    gen-config \
"

FEATURE_PACKAGES_gen-config = " \
    initramfs-module-gen-config \
"

IMAGE_FEATURES += "gen-config"

IMAGE_FSTYPES = "${INITRAMFS_FSTYPES}"
inherit core-image

BAD_RECOMMENDATIONS += "busybox-syslog"
