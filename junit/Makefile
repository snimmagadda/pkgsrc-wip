# $NetBSD: Makefile,v 1.2 2012/10/01 21:43:26 asau Exp $
#

DISTNAME=	junit4.8.2
PKGNAME=	junit-4.8.2
CATEGORIES=	devel java
MASTER_SITES=	http://github.com/downloads/KentBeck/junit/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.junit.org/
COMMENT=	Automated testing framework for Java
LICENSE=	cpl-1.0

NO_BUILD=	yes
USE_JAVA=	run
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	lib/java/junit share/doc/junit

do-install:
	${INSTALL_DATA} ${WRKSRC}/junit-4.8.2.jar ${DESTDIR}${PREFIX}/lib/java/junit
	${LN} -s ${DESTDIR}${JAVADIR}/junit-4.8.2.jar ${DESTDIR}${PREFIX}/lib/java/junit/junit.jar
	cd ${WRKSRC} && pax -rw -pp doc  ${DESTDIR}${PREFIX}/share/doc/junit
	cd ${WRKSRC} && pax -rw -pp  javadoc  ${DESTDIR}${PREFIX}/share/doc/junit


.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
