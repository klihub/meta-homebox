HOMEBOX_EDITORS ??= ""

IMAGE_FEATURES[validitems] += " \
    editors \
"

FEATURE_PACKAGES_editor = " \
    ${@bb.utils.contains('HOMEBOX_EDITORS', ':q!', '', 'vim', d)} \
    ${@bb.utils.contains('HOMEBOX_EDITORS', 'C-xC-c', '', 'uemacs', d)} \
"
