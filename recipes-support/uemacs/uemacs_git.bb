SUMMARY = "uEmacs"
SECTION = "console/utils"
DEPENDS = "ncurses gettext-native"

LICENSE = "uemacs"
LIC_FILES_CHKSUM = "file://LICENSE;md5=5c29ce962aad71cfdc50d6b1ed5d0427"

SRC_URI = " \
    git://github.com/klihub/uemacs.git \
"

SRCREV = "2a0b33d8ff36595ab1bce9cb7567a0c9f40c939e"

S = "${WORKDIR}/git"

inherit autotools update-alternatives

FILES_${PN} += " \
    ${libdir}/emacs.hlp \
    ${libdir}/emacs.rc \
"

do_configure_prepend() {
    cd ${S}
    ./bootstrap
    cd -
}

do_install_append () {
    mv ${D}${bindir}/${BPN} ${D}${bindir}/${BPN}.${BPN}
}

ALTERNATIVE_${PN} = "uemacs"
ALTERNATIVE_TARGET = "${bindir}/${BPN}.${BPN}"
ALTERNATIVE_LINK_NAME[emacs] = "${bindir}/uemacs"
ALTERNATIVE_PRIORITY = "100"
