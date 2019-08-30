$NetBSD$

Add placeholder for pkgsrc PREFIX to beginning of search list.

--- src/main.cc.orig	2018-08-05 08:20:26.000000000 +0000
+++ src/main.cc
@@ -301,6 +301,7 @@ static void Determine_InstallPath(const 
 #else
 	static const char *prefixes[] =
 	{
+		"PKGSRC_PREFIX",
 		"/usr/local",
 		"/usr",
 		"/opt",
