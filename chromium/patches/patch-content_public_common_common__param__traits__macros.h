$NetBSD$

--- content/public/common/common_param_traits_macros.h.orig	2020-07-08 21:40:42.000000000 +0000
+++ content/public/common/common_param_traits_macros.h
@@ -315,7 +315,7 @@ IPC_STRUCT_TRAITS_BEGIN(blink::mojom::Re
   IPC_STRUCT_TRAITS_MEMBER(accept_languages)
   IPC_STRUCT_TRAITS_MEMBER(disable_client_blocked_error_page)
   IPC_STRUCT_TRAITS_MEMBER(plugin_fullscreen_allowed)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   IPC_STRUCT_TRAITS_MEMBER(system_font_family_name)
 #endif
 #if defined(OS_WIN)
