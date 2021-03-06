$NetBSD$

--- base/process/memory.h.orig	2020-06-25 09:31:18.000000000 +0000
+++ base/process/memory.h
@@ -24,7 +24,7 @@ BASE_EXPORT void EnableTerminationOnOutO
 // Crash reporting classifies such crashes as OOM.
 BASE_EXPORT void TerminateBecauseOutOfMemory(size_t size);
 
-#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_AIX) || defined(OS_BSD)
 BASE_EXPORT extern size_t g_oom_size;
 
 // The maximum allowed value for the OOM score.
