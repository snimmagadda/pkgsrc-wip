# $NetBSD$

###########################################################
#               Generated by fbsd2pkg                     #
###########################################################

DISTNAME=	gmap-${PORTVERSION:C|\.|-|g}
PKGNAME=	gmap-${PORTVERSION}
CATEGORIES=	biology
MASTER_SITES=	http://research-pub.gene.com/gmap/src/
DISTFILES=	gmap-gsnap-${PORTVERSION:C|\.|-|g}${EXTRACT_SUFX}

MAINTAINER=	bacon@NetBSD.org
COMMENT=	Genomic Mapping and Alignment Program for mRNA and EST Sequences
#LICENSE=

# Pessimistic assumption.  Test and change if possible.
# MAKE_JOBS_SAFE=	no

ONLY_FOR_PLATFORM=

# FIXME: Add shebang fixes for perl scripts

# Just assuming C and C++: Adjust this!
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

PORTVERSION=	2014.07.04
DATADIR=	${PREFIX}/share/gmap
DOCSDIR=	${PREFIX}/share/doc/gmap

.include "../../mk/bsd.pkg.mk"
