# dnf
DNF_SITE = file://$(TOPDIR)/core
DNF_INSTALL_TARGET = yes
DNF_TARBALL = dnf.tar.xz
DNF_SOURCE = ${DNF_TARBALL}
DNF_LICENSE = GPL-2.0
DNF_CPE_ID_VENDOR = dnf
$(eval $(cmake-package))
