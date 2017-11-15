# Set stricter than default QA checks.

CONVERT_TO_ERRORS = " \
    already-stripped \
    compile-host-path \
    install-host-path \
    installed-vs-shipped \
    ldflags \
    pn-overrides \
    rpaths \
    staticdev \
    useless-rpaths \
    build-deps \
"

WARN_QA_remove = "${CONVERT_TO_ERRORS}"
ERROR_QA_append = " ${CONVERT_TO_ERRORS}"
