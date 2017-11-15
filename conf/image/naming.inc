# By default use timestamp for BUILD_ID (don't rebuild when just time changes).
BUILD_ID ?= "${DATETIME}"
BUILD_ID[vardepsexclude] += "DATETIME"
IMAGE_BUILDINFO_append = " BUILD_ID"

# Generate images with this name.
IMAGE_NAME = "${IMAGE_BASENAME}-${BUILD_ID}-${MACHINE}"

