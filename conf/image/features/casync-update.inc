IMAGE_FEATURES[validitems] += " \
    casync-update \
"

FEATURE_PACKAGES_casync-update = " \
    casync \
"

#
# Unfortunately a straightforward conditional inherit like
#
#     inherit {@bb.utils.contains('IMAGE_FEATURES', 'casync-update',
#                                     'image-casync', '', d)}
#
# does not work here. In our scheme of things, 'casync-update' gets added
# to IMAGE_FEATURES only after this file has been processed by a require
# and it looks like that inherits are processed immediately while processing
# a file.
#
# Therefore, we need to unconditionally inherit image-casync.inc and
# teach the tasks there to opt out if the necessary feature is not on.
#

inherit image-casync
