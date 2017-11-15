# Don't build ISO images.
NOISO = "1"

# Don't build images in HDD format (loopback file in VFAT partition).
NOHDD = "1"

# Build compressed WIC-based full disk images.
HOMEBOX_IMAGE_TYPES ??= "wic.xz"
IMAGE_FSTYPES_append = " ${HOMEBOX_IMAGE_TYPES}"

# Remove all types thah pull in image-live.bbclass (to get rid of its deps).
IMAGE_FSTYPES_remove = "live hddimg iso"

