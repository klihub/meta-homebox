IMAGE_FEATURES[validitems] += " \
    autologin \
"

HOMEBOX_LOCAL_GETTY_SERVICES ?= " \
    ${IMAGE_ROOTFS}${systemd_system_unitdir}/serial-getty@.service \
"

homebox_enable_autologin () {
    for s in ${HOMEBOX_LOCAL_GETTY_SERVICES}; do
        if [ -f $s ]; then
            sed -i -e "s/ -o '[^']*'//" $s
            sed -i -e 's/^\(ExecStart *=.*getty \)/\1--autologin root/' $s
        else
            bbwarn "Failed to enable autologin ($HOMEBOX_LOCAL_GETTY_SERVICES)."
            bbfatal "$s not found"
        fi
    done
}

ROOTFS_POSTPROCESS_COMMAND += " \
    ${@bb.utils.contains('IMAGE_FEATURES', 'autologin', \
           'homebox_enable_autologin;', '', d)} \
"
