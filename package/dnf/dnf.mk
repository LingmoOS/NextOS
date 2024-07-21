# dnf
DNF_VERSION = master
DNF_SITE = https://github.com/rpm-software-management/dnf.git
DNF_MEthod = git
DNF_INSTALL_TARGET = yes
DNF_LICENSE = GPL-2.0
DNF_CPE_ID_VENDOR = dnf
$(eval $(autotools-package))
