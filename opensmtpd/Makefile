# $NetBSD$

VERSION=	6.7.1p1
DISTNAME=	opensmtpd-${VERSION}
CATEGORIES=	mail net
MASTER_SITES=	https://www.opensmtpd.org/archives/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.opensmtpd.org/
COMMENT=	The OpenSMTPD mail transfer agent, a replacement for sendmail
LICENSE=	isc AND modified-bsd AND 2-clause-bsd

CONFLICTS+=	courier-mta-[0-9]* fastforward>=0.51nb2 sendmail-[0-9]*
CONFLICTS+=	esmtp>=1.2 nullmailer-[0-9]* postfix-[0-9]*

BUILD_DEFS+=	VARBASE

USE_LANGUAGES=	c
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config yacc
USE_TOOLS+=	automake aclocal autoheader autoconf

SMTPD_HOME=	${VARBASE}/chroot/smtpd
OWN_DIRS=	${SMTPD_HOME}

PKG_GROUPS=		_smtpd _smtpq
PKG_USERS=		_smtpd:_smtpd _smtpq:_smtpq
PKG_GECOS._smtpd=	OpenSMTPD pseudo-user
PKG_HOME._smtpd=	${SMTPD_HOME}
PKG_GECOS._smtpq=	OpenSMTPD pseudo-user
PKG_HOME._smtpq=	${SMTPD_HOME}

GNU_CONFIGURE=		yes
USE_DB185=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-mantype=man
CONFIGURE_ARGS+=	--with-privsep-path=${SMTPD_HOME}
CONFIGURE_ARGS+=	--with-ssl-dir=${SSLBASE:Q}
CONFIGURE_ARGS+=	--enable-table-db
CONFIGURE_ARGS+=	--without-zlib-version-check

CFLAGS.SunOS+=		-D__EXTENSIONS__

EXAMPLEDIR=	${PREFIX}/share/examples/opensmtpd
CONF_FILES=	${EXAMPLEDIR}/smtpd.conf ${PKG_SYSCONFDIR}/smtpd.conf

MAKE_DIRS+=	${VARBASE}/empty ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700

RCD_SCRIPTS=	opensmtpd

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/mailer.conf
SUBST_VARS.paths=	PREFIX
SUBST_STAGE.paths=	pre-configure

SUBST_CLASSES+=			exampledir
SUBST_STAGE.exampledir=		pre-configure
SUBST_MESSAGE.exampledir=	Fixing exampledir path
SUBST_FILES.exampledir=		mk/smtpd/Makefile.am
SUBST_SED.exampledir+=		-e 's,@EXAMPLE_DIR@,${EXAMPLEDIR},'

post-extract:
	cp ${FILESDIR}/mailer.conf ${WRKDIR}/mailer.conf

pre-configure:
	cd ${WRKSRC} && ${PREFIX}/bin/libtoolize --copy --force
	cd ${WRKSRC} && ${TOOLS_CMD.aclocal}
	cd ${WRKSRC} && ${TOOLS_CMD.autoconf}
	cd ${WRKSRC} && ${TOOLS_CMD.autoheader}
	cd ${WRKSRC} && ${TOOLS_CMD.automake} --foreign --add-missing --copy

post-install:
	${INSTALL_DATA} ${WRKDIR}/mailer.conf \
		${DESTDIR}${EXAMPLEDIR}/mailer.conf

.include "../../databases/db5/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libasr/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
