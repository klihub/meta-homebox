DESCRIPTION = "A Configuration Generator/Generic Configurator Framework"
HOMEPAGE = "https://github.com/klihub/gen-config.git/"
LICENSE = "BSD"
LIC_FILES_CHKSUM = "file://LICENSE.BSD;md5=62272bd11c97396d4aaf1c41bc11f7d8"
DEPENDS = "python3"

PV = "2017.11"

SRC_URI = " \
  git://github.com/klihub/gen-config.git;protocol=https \
"
SRCREV = "4cdda36d336c7f3f4a24b8cc92a24786fb69bd27"

S = "${WORKDIR}/git"

FILES_${PN} += "${datadir}"

# The non-obvious ones are for io: ipaddress, crypt: hashlib, shell: glob.
RDEPENDS_${PN} += " \
    python3-argparse \
    python3-re \
    python3-io \
    python3-crypt \
    python3-shell \
"

inherit distutils3
