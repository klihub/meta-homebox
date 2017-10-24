SUMMARY = "IoT Reference OS Kit image for HomeBox profile."
DESCRIPTION = "IoT Reference OS Kit image for HomeBox profile."

REFKIT_IMAGE_HOMEBOX_EXTRA_FEATURES ?= " \
"
REFKIT_IMAGE_HOMEBOX_EXTRA_INSTALL ?= " \
    packagegroup-homebox-router \
"

REFKIT_IMAGE_EXTRA_FEATURES += "${REFKIT_IMAGE_HOMEBOX_EXTRA_FEATURES}"
REFKIT_IMAGE_EXTRA_INSTALL += "${REFKIT_IMAGE_HOMEBOX_EXTRA_INSTALL}"

# Example for customization in local.conf when building
# refkit-image-homebox.bb:
# IMAGE_BASENAME_pn-refkit-image-homebox = "my-refkit-image-homebox"
# REFKIT_IMAGE_HOMEBOX_EXTRA_INSTALL_append = " my-own-package"
# REFKIT_IMAGE_HOMEBOX_EXTRA_FEATURES_append = " dev-pkgs"

inherit refkit-image
