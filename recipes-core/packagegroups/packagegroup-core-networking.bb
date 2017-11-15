SUMMARY = "Home Box Core networking package group."
LICENSE = "MIT"
PR = "r1"

inherit packagegroup

RDEPENDS_${PN} = "\
    connman \
"

# Poky doesn't feature systemd so add libnss-myhostname conditionally
RDEPENDS_${PN}_append = " libnss-myhostname"

