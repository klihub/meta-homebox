IMAGE_FEATURES[validitems] += " \
    preset-password \
"

HOMEBOX_PRESET_PASSWORDS ??= ""

homebox_preset_passwords () {
    if [ -z "${HOMEBOX_PRESET_PASSWORDS}" ]; then
        bbwarn "preset-password IMAGE_FEATURE is set, but no passwords"
        bbwarn "are actually preset (HOMEBOX_PRESET_PASSWORDS)..."
        return 0
    fi

    _pp="${HOMEBOX_PRESET_PASSWORDS}"
    while [ -n "$_pp" ]; do
        _e=$(echo $_pp | cut -d ' ' -f1)
        _pp=$(echo $_pp | cut -s -d ' ' -f2-)

        case $_e in
             *=*) _u=$(echo $_e | cut -d = -f1); _p=$(echo $_e | cut -d = -f2);;
             *)   _u=root; _p="$_e";;
        esac

        case $_p in
             \$?\$*) ;;
             *)      _p=$(python -c "import crypt; print crypt.crypt('$_p')");;
        esac

        bbnote "Setting password entry for $_u..."
        if ! sed -i -e "s#^$_u:[^:]*:#$_u:$_p:#" \
                 ${IMAGE_ROOTFS}${sysconfdir}/shadow; then
            bbfatal "Failed to set password entry for user $_u."
        fi
    done
}

ROOTFS_POSTPROCESS_COMMAND += " \
    ${@bb.utils.contains('IMAGE_FEATURES', 'preset-password', \
           'homebox_preset_passwords;', '', d)} \
"
