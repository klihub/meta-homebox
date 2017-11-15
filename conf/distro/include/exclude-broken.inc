HOMEBOX_REMOVE_PACKAGES ?= " \
    oprofileui-server \
    lttng-tools \
"

RDEPENDS_packagegroup-core-device-devel_remove_pn-packagegroup-core-device-devel = "${HOMEBOX_REMOVE_PACKAGES}"
RDEPENDS_packagegroup-core-tools-profile_remove_pn-packagegroup-core-tools-profile = "${HOMEBOX_REMOVE_PACKAGES}"
