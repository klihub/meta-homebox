IMAGE_FEATURES[validitems] += " \
    authorized-keys \
"

HOMEBOX_AUTHORIZED_KEYS ?= ""

homebox_install_authorized_keys () {
    if [ -z "${HOMEBOX_AUTHORIZED_KEYS}" ]; then
        bbwarn "Image feature 'authorized-keys' is enabled but no"
        bbwarn "actual authorized keys are set (HOMEBOX_AUTHORIZED_KEYS)..."
        return 0
    fi

    for e in ${HOMEBOX_AUTHORIZED_KEYS}; do
        case $e in
            *:*) user=${e%:*}; file=${e#*:};;
              *) user=root; file=$e;;
        esac

        bbnote "Installing authorized keys ($file) for $user..."

        home=$(cat ${IMAGE_ROOTFS}${sysconfdir}/passwd | grep "^$user:" | \
                   cut -d : -f6)
        if [ -z "$home" ]; then
            bbfatal "Failed to determine home for $user (for SSH keys)."
        fi

        mkdir -p ${IMAGE_ROOTFS}$home/.ssh
        cat $file >> ${IMAGE_ROOTFS}$home/.ssh/authorized_keys
        chown $user ${IMAGE_ROOTFS}$home/.ssh/authorized_keys
        chown $user ${IMAGE_ROOTFS}$home/.ssh
        chmod go-rwx ${IMAGE_ROOTFS}$home/.ssh/authorized_keys
        chmod go-rwx ${IMAGE_ROOTFS}$home/.ssh
    done
}

ROOTFS_POSTPROCESS_COMMAND += " \
    ${@bb.utils.contains('IMAGE_FEATURES', 'authorized-keys', \
          'homebox_install_authorized_keys;', '', d)} \
"
