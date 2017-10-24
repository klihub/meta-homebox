SUMMARY = "HomeBox Basic Router Support"
LICENSE = "MIT"

inherit packagegroup

RDEPENDS_${PN} = " \
    dhcp-server \
    dhcp-server-config \
    dhcp-client \
    nftables \
    bind \
    dnsmasq \
    openssh-sshd \
    openssh-ssh \
    openssh-scp \
"

