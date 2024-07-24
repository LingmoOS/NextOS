# pacman
PACMAN_SITE = file://$(TOPDIR)/core
PACMAN_INSTALL_TARGET = yes
PACMAN_TARBALL = pacman.tar.xz
PACMAN_SOURCE = ${DNF_TARBALL}
PACMAN_LICENSE = GPL-2.0
PACMAN_CPE_ID_VENDOR = pacman
$(eval $(meson-package))
