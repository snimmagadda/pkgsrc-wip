# $NetBSD: Makefile,v 1.7 2014/04/03 01:21:22 outpaddling Exp $

DISTNAME=	APE-3.5.3.13
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	fd9ca94533355b1a0990b76c33eb8052d30eacdb

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/APE
COMMENT=	Another Programmer's Editor
LICENSE=	2-clause-bsd

DEPENDS=	webbrowser>=0:../../wip/webbrowser

MAKE_ENV+=	STAGEDIR=${DESTDIR}

pre-build:
	cd ${WRKSRC} && ${MAKE} LOCALBASE=${PREFIX} depend

.include "../../wip/libpare/buildlink3.mk"
.include "../../wip/libbacon/buildlink3.mk"
.include "../../wip/twintk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
