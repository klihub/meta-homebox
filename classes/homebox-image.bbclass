LICENSE = "MIT"

HOMEBOX_IMAGE_EXTRA_FEATURES ?= ""
HOMEBOX_IMAGE_EXTRA_INSTALL ?= ""

IMAGE_INSTALL = " \
    kernel-modules \
    packagegroup-core-boot \
    ${MACHINE_EXTRA_RDEPENDS} \
    ${MACHINE_EXTRA_RRECOMMENDS} \
    ${ROOTFS_BOOTSTRAP_INSTALL} \
    ${CORE_IMAGE_EXTRA_INSTALL} \
    ${HOMEBOX_IMAGE_EXTRA_INSTALL} \
"

# Declare image features.
require conf/image/features/authorized-keys.inc
require conf/image/features/preset-password.inc
require conf/image/features/autologin.inc
require conf/image/features/casync-update.inc
require conf/image/features/networking.inc
require conf/image/features/editors.inc
require conf/image/features/tools-debug.inc
require conf/image/features/tools-develop.inc

# Configure the image types we build.
require conf/image/types.inc

# Set up image naming scheme, rootfs labeling, initramfs.
require conf/image/naming.inc
require conf/image/labels.inc
require conf/image/initramfs.inc

# Choose and configure image features.
HOMEBOX_PRESET_PASSWORDS ?= "root=root"

IMAGE_FEATURES += " \
    preset-password \
    authorized-keys \
    ssh-server-openssh \
    casync-update \
    editors \
    ${HOMEBOX_IMAGE_EXTRA_FEATURES} \
"

# We'll build syslinux-booted full disk images.
IMAGE_CLASSES += "image-syslinux"

inherit core-image extrausers image-buildinfo
inherit systemd-sysusers

require conf/image/linguas.inc
require conf/image/os-release.inc
