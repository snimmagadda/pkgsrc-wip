$NetBSD: patch-src_librustc__codegen__ssa_back_linker.rs,v 1.1 2019/09/09 16:19:49 adam Exp $

Do not use @rpath on Darwin.

--- src/librustc_codegen_ssa/back/linker.rs.orig	2020-08-24 15:00:49.000000000 +0000
+++ src/librustc_codegen_ssa/back/linker.rs
@@ -244,7 +244,7 @@ impl<'a> GccLinker<'a> {
             // the right `-Wl,-install_name` with an `@rpath` in it.
             if self.sess.opts.cg.rpath || self.sess.opts.debugging_opts.osx_rpath_install_name {
                 self.linker_arg("-install_name");
-                let mut v = OsString::from("@rpath/");
+                let mut v = OsString::from("@PREFIX@/lib/");
                 v.push(out_filename.file_name().unwrap());
                 self.linker_arg(&v);
             }
