SUMMARY = "Home Box image."
DESCRIPTION = "Home Box image."

HOMEBOX_IMAGE_EXTRA_FEATURES += ""
HOMEBOX_IMAGE_EXTRA_INSTALL += " \
    packagegroup-homebox-router \
"

RDEPENDS_${PN} = "syslinux"

inherit homebox-image

WKS_FILE = "homebox-syslinux.wks.in"
