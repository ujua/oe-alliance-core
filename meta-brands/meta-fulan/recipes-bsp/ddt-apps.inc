HOMEPAGE = "https://github/Duckbox-Developers/apps"
SECTION = "base"
require conf/license/license-gplv2.inc
DEPENDS = "fulan-dvb-modules-${MACHINE}"

inherit autotools gitpkgv

SRCREV = "36c86d7c069c75d258cde0a0756c669e0294cd54"
PV = "1.0+git${SRCPV}"
PKGV = "1.0+git${GITPKGV}"

SRC_URI = " \
    git://github.com/Duckbox-Developers/apps.git;protocol=git \
    file://libtool_dont_stop.patch \
"

S = "${WORKDIR}/git/tools"

EXTRA_OECONF = "--enable-silent-rules --prefix="

LDFLAGS += "-lpthread -lrt"

do_configure() {
    cd ${S}
    ./autogen.sh
    oe_runconf
}

do_compile() {
    cd ${S}
    oe_runmake  'DESTDIR=${D}' 'SUBDIRS=${@d.getVar('PN',1).replace('-', '_')}' 
}

do_install() {
    cd ${S}
    oe_runmake  'DESTDIR=${D}' 'SUBDIRS=${@d.getVar('PN',1).replace('-', '_')}' install
}

