$NetBSD: patch-UTIL_second.f,v 1.1.1.1 2012/03/02 20:26:08 outpaddling Exp $

#

--- UTIL/second.f.orig	1995-10-02 18:56:44.000000000 +0000
+++ UTIL/second.f
@@ -21,7 +21,8 @@
 *     ..
 *     .. External Functions ..
       REAL               ETIME
-      EXTERNAL           ETIME
+*  ETIME is intrinsic, so this causes undefined reference errors in newer gcc
+*      EXTERNAL           ETIME
 *     ..
 *     .. Executable Statements ..
 *
