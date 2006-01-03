# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/01/03 17:23:47 debolaz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PARROT_BUILDLINK3_MK:=	${PARROT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	parrot
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nparrot}
BUILDLINK_PACKAGES+=	parrot

.if !empty(PARROT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.parrot+=		parrot>=0.4.0
BUILDLINK_PKGSRCDIR.parrot?=		../../lang/parrot
.endif	# PARROT_BUILDLINK3_MK

.include "../../textproc/icu/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
