DISTRO_FEATURES_append = " systemd"

VIRTUAL-RUNTIME_init_manager = "systemd"
VIRTUAL-RUNTIME_initscripts = ""
DISTRO_FEATURES_BACKFILL_CONSIDERED = "sysvinit"

# Prefer systemd way of creating getty@.service symlinks.
PACKAGECONFIG_append_pn-systemd = " serial-getty-generator"
