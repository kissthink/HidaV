# common stuff for all HydraIP images

INC_PR = "r6"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/LICENSE;md5=3f40d7994397109285ec7b81fdeb3b58"

DEPENDS += "task-base-extended \
	   "
IMAGE_INSTALL += "task-base-extended \

IMAGE_PREPROCESS_COMMAND = "rootfs_update_timestamp"

IMAGE_INSTALL += " \
  angstrom-task-boot \
  task-basic \
  ${CONMANPKGS} \
"
CONMANPKGS = "connman connman-plugin-loopback connman-plugin-ethernet connman-plugin-wifi connman-systemd"
CONMANPKGS_libc-uclibc = ""

# IMAGE_DEV_MANAGER   = "udev"
IMAGE_INIT_MANAGER  = "systemd"
IMAGE_INITSCRIPTS   = " "
IMAGE_LOGIN_MANAGER = "tinylogin shadow"

inherit image

IMAGE_INSTALL += " \
  kernel-modules \
  htop \
  bash \
"

# systemd-analyze depends
IMAGE_INSTALL += " \
  python \
  python-dbus \
  python-pycairo \
"

# helpers
IMAGE_INSTALL += " \
  vim \
  mtd-utils \
  mc \
  nano \  
"

# SDK
IMAGE_INSTALL_hidav += " \
  rootfs-overlay \
"