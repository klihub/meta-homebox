# Set OS release during image creation to ${BUILD_ID}.
homebox_set_os_release () {
    for d in /etc ${sysconfdir} ${libdir}; do
        if [ ! -f ${IMAGE_ROOTFS}$d/os-release ]; then
            continue;
        fi

        sed -i -e 's/build-id-to-be-added-during-image-creation/${BUILD_ID}/' \
            ${IMAGE_ROOTFS}$d/os-release
    done
}
homebox_set_os_release[vardepsexclude] = " \
    BUILD_ID \
"

ROOTFS_POSTPROCESS_COMMAND += "homebox_set_os_release; "
