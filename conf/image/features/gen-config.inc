IMAGE_FEATURES[validitems] += " \
    gen-config \
"

FEATURE_PACKAGES_gen-config = " \
    gen-config \
"

HOMEBOX_CONFIG_FILES ?= ""

homebox_config_copy_files () {
    # Copy the configuration file(s) in place. By convention the first one
    # is the main config file (which can then include others). Make sure it
    # is found by a standard name by creating a symbolic link if necessary.

    mkdir -p ${IMAGE_ROOTFS}/conf/config

    if [ -z "${HOMEBOX_CONFIG_FILES}" ]; then
        bbnote "HOMEBOX_CONFIG_FILES not set, skipping..."
        return 0
    fi

    cp ${HOMEBOX_CONFIG_FILES} ${IMAGE_ROOTFS}/conf/config
    files="${HOMEBOX_CONFIG_FILES}"
    main=${files%% *}
    base=${main##*/}
    if [ "$base" != "config.cfg" ]; then
        ln -sf $base ${IMAGE_ROOTFS}/conf/config/config.cfg
    fi
}

homebox_config_fstab () {
    >> ${IMAGE_ROOTFS}/etc/fstab cat <<EOF
LABEL=${HOMEBOX_LABEL_CONFFS}    /conf    auto    defaults    0  0
EOF
}

ROOTFS_POSTPROCESS_COMMAND += " \
    ${@bb.utils.contains('IMAGE_FEATURES', 'gen-config', \
          'homebox_config_copy_files; homebox_config_fstab;', '', d)} \
"

# Extra partition to create if our image feature is enabled.
HOMEBOX_WIC_CONFFS_PARTITION = " \
  ${@' '.join(['part /config --source rootfs --fstype=ext4 --align 1024', \
               '--fixed-size ${HOMEBOX_CONFFS_SIZE}M', \
               '--rootfs-dir=${IMAGE_ROOTFS}/conf', \
               '--label=${HOMEBOX_LABEL_CONFFS}'])} \
"

HOMEBOX_WIC_CONFFS_EXCLUDE = " \
    ${@bb.utils.contains('IMAGE_FEATURES', 'gen-config', \
                             '--exclude-path=conf/', '', d)} \
"