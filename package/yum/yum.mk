# yum
DNF_VERSION = master
DNF_SITE = https://github.com/rpm-software-management/yum.git
DNF_MEthod = git
DNF_INSTALL_TARGET = yes
DNF_LICENSE = GPL-2.0
DNF_CPE_ID_VENDOR = yum
$(eval $(autotools-package))
