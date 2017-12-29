DESCRIPTION = "A Configuration Generator/Generic Configurator Framework"
HOMEPAGE = "https://github.com/klihub/gen-config.git/"
LICENSE = "BSD"
LIC_FILES_CHKSUM = "file://LICENSE.BSD;md5=62272bd11c97396d4aaf1c41bc11f7d8"
DEPENDS = "python3"

PV = "2017.11"

SRC_URI = " \
  git://github.com/klihub/gen-config.git;protocol=https \
"
SRCREV = "8b4e583aa50802f88d1f2cae063bf96d434817d0"

S = "${WORKDIR}/git"

FILES_${PN} += " \
    ${datadir} \
    ${systemd_unitdir}/system \
"

# The non-obvious ones are for io: ipaddress, crypt: hashlib, shell: glob.
RDEPENDS_${PN} += " \
    python3-argparse \
    python3-re \
    python3-io \
    python3-crypt \
    python3-shell \
"

SYSTEMD_SERVICE_${PN} = "conffs-prepare.service conffs-mount.service"
SYSTEMD_AUTO_ENABLE = "enable"

inherit distutils3 systemd

do_install_append () {
    # distutils3 runs setup.py with the options
    #   --prefix=${D}/${prefix} --install-data=${D}/${datadir}
    # with datadir being set to /usr/share. This screws things up for
    # us, because relative paths get relocated under /usr/share instead
    # of the intended /usr. We try to fix things up here...
    if [ -d ${D}/${datadir}/lib/systemd ]; then
        mkdir -p ${D}/${libdir}
        mv -v ${D}/${datadir}/lib/systemd ${D}/${libdir}
    fi
}
