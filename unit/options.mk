# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.unit
PKG_SUPPORTED_OPTIONS=	debug devkit inet6 ssl
PKG_SUGGESTED_OPTIONS=	inet6 ssl

PLIST_VARS+=		devkit

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--debug
.endif

.if !empty(PKG_OPTIONS:Mdevkit)
PLIST.devkit=		yes
.endif

.if empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=--no-ipv6
.endif

.if !empty(PKG_OPTIONS:Mssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--openssl
.endif
