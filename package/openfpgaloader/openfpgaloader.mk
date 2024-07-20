################################################################################
#
# openfpgaloader
#
################################################################################

OPENFPGALOADER_VERSION = 0.11.0
OPENFPGALOADER_SITE = $(call github,trabucayre,openFPGALoader,v$(OPENFPGALOADER_VERSION))
OPENFPGALOADER_LICENSE = Apache-2.0
OPENFPGALOADER_LICENSE_FILES = LICENSE
OPENFPGALOADER_DEPENDENCIES = libftdi1 zlib

ifeq ($(LINGMO_PACKAGE_HAS_UDEV),y)
OPENFPGALOADER_DEPENDENCIES += udev
OPENFPGALOADER_CONF_OPTS += -DENABLE_UDEV=ON
else
OPENFPGALOADER_CONF_OPTS += -DENABLE_UDEV=OFF
endif

ifeq ($(LINGMO_PACKAGE_OPENFPGALOADER_CMSIS),y)
OPENFPGALOADER_DEPENDENCIES += hidapi
OPENFPGALOADER_CONF_OPTS += -DENABLE_CMSISDAP=ON
else
OPENFPGALOADER_CONF_OPTS += -DENABLE_CMSISDAP=OFF
endif

ifeq ($(LINGMO_PACKAGE_OPENFPGALOADER_LIBGPIOD),y)
OPENFPGALOADER_DEPENDENCIES += libgpiod
OPENFPGALOADER_CONF_OPTS += -DENABLE_LIBGPIOD=ON
else
OPENFPGALOADER_CONF_OPTS += -DENABLE_LIBGPIOD=OFF
endif

$(eval $(cmake-package))
