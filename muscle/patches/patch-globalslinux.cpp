$NetBSD$

# Portability

--- globalslinux.cpp.orig	Tue Nov 30 05:09:50 2004
+++ globalslinux.cpp	Mon Jul  4 11:13:18 2005
@@ -7,6 +7,12 @@
 #include <errno.h>
 #include <stdio.h>
 #include <fcntl.h>
+#if __FreeBSD__ > 2
+#include <kvm.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <sys/user.h>
+#endif // __FreeBSD__ > 2
 
 const int ONE_MB = 1000000;
 const int MEM_WARNING_THRESHOLD = 20*ONE_MB;
@@ -39,6 +45,34 @@
 	return szCmdLine;
 	}
 
+#if __FreeBSD__ > 2
+double GetMemUseMB()
+	{
+	kvm_t *kd;
+	struct kinfo_proc *ki;
+	vm_size_t size;
+	int nproc;
+
+	kd = kvm_open(NULL, "/dev/null", NULL, O_RDONLY, "kvm_open");
+	if (kd == NULL)
+		{
+		static bool Warned = false;
+		if (!Warned)
+			{
+			Warned = true;
+			Warning("*Warning* Cannot open KVM");
+			}
+		return 0;
+		}
+
+	ki = kvm_getprocs(kd, KERN_PROC_PID, getpid(), &nproc);
+	size = ki->ki_size;
+
+	kvm_close(kd);
+
+	return ((double) size)/1e6;
+	}
+#else // __FreeBSD__ > 2
 double GetMemUseMB()
 	{
 	static char statm[64];
@@ -83,6 +117,7 @@
 
 	return ((double) Pages * (double) PageSize)/1e6;
 	}
+#endif // __FreeBSD__ > 2
 
 void SaveCmdLine(int argc, char *argv[])
 	{
@@ -118,6 +153,28 @@
 		dPeakMemUseMB = dMB;
 	}
 
+#if __FreeBSD__ > 2
+double GetRAMSizeMB()
+	{
+	const double DEFAULT_RAM = 500;
+	unsigned int physmem;
+	size_t len = sizeof physmem;
+	static int mib[2] = { CTL_HW, HW_PHYSMEM };
+
+	if (sysctl(mib, 2, &physmem, &len, NULL, 0))
+		{
+		static bool Warned = false;
+		if (!Warned)
+			{
+			Warned = true;
+			Warning("*Warning* Cannot get hw.physmem");
+			}
+		return DEFAULT_RAM;
+		}
+
+	return ((double) physmem)/1e6;
+	}
+#else // __FreeBSD__ > 2
 double GetRAMSizeMB()
 	{
 	const double DEFAULT_RAM = 500;
@@ -168,5 +225,6 @@
 	int Bytes = atoi(pMem+9)*1000;
 	return ((double) Bytes)/1e6;
 	}
+#endif // __FreeBSD__ > 2
 
 #endif	// !WIN32
