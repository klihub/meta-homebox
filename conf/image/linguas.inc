# This is a workaround for some broken packages (for instance bsdtar), lifted
# over from intel-iot-refkit.

# Take the first language in IMAGE_LINGUAS and turn it into a LANG.
def homebox_lingua_to_lang(d):
   all = d.getVar('IMAGE_LINGUAS').split()

   if not all:
       return ''
   first = all[0].split('-')

   if len(first) != 2:
       return ''

   return first[0] + '_' + first[1].upper()

# Set up /etc/locale.conf.
homebox_configure_locale_conf () {
    if [ -z "${HOMEBOX_IMAGE_LANG}" ]; then
        return 0
    fi

    echo 'LANG=${HOMEBOX_IMAGE_LANG}' > ${IMAGE_ROOTFS}${sysconfdir}/locale.conf
}

HOMEBOX_IMAGE_LANG ?= "${@homebox_lingua_to_lang(d)}"
ROOTFS_POSTPROCESS_COMMAND += "homebox_configure_locale_conf; "
