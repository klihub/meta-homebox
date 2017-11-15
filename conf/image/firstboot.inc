# Make sure systemd-firstboot is not run even on first boot.
homebox_disable_firstboot () {
    for i in /etc/systemd /lib/systemd /usr/lib/systemd /bin /usr/bin; do
        d="${IMAGE_ROOTFS}$i"
        if [ -d "$d" ] && [ ! -h "$d" ]; then
            for e in $(find "$d" -name systemd-firstboot.service -o \
                                 -name systemd-firstboot.service.d -o \
                                 -name systemd-firstboot); do
                echo "disable_firstboot: removing $e"
                rm -rf "$e"
            done
        fi
    done
}

ROOTFS_POSTPROCESS_COMMAND += "homebox_disable_firstboot; "