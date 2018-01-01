DESCRIPTION = "A Configuration Generator/Generic Configurator Framework"
HOMEPAGE = "https://github.com/klihub/gen-config.git/"
LICENSE = "BSD"
LIC_FILES_CHKSUM = "file://LICENSE.BSD;md5=62272bd11c97396d4aaf1c41bc11f7d8"
DEPENDS = "python3"

PV = "2017.11"

SRC_URI = " \
  git://github.com/klihub/gen-config.git;protocol=https \
  file://initramfs-gen-config \
"
SRCREV = "e96692a0e013bc7ae0ba937626c17c934e0a48e8"

S = "${WORKDIR}/git"

# The non-obvious ones are for io: ipaddress, crypt: hashlib, shell: glob.
RDEPENDS_${PN} += " \
    python3-argparse \
    python3-re \
    python3-io \
    python3-crypt \
    python3-shell \
"

PACKAGES += "initramfs-module-gen-config"

FILES_${PN} += " \
    ${datadir} \
"

FILES_initramfs-module-gen-config = " \
    /init.d/98-genconfig \
"

inherit distutils3

do_install_append () {
    W="${WORKDIR}"

    # Install our initramfs module.
    install -m 0755 -d ${D}/init.d
    install -m 0755 -T ${W}/initramfs-gen-config ${D}/init.d/98-genconfig
}
