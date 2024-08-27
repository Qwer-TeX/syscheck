#include "disk.h"
#include "utils.h"
#include <stdio.h>
#include <sys/statvfs.h>

void check_disk_space(const char *path) {
  struct statvfs vfs;
  if (statvfs(path, &vfs) == 0) {
    print_colored("Disk Space Information:\n", COLOR_YELLOW);
    printf("  Filesystem mounted at '%s':\n", path);
    printf("    Total Space: %s\n", format_size(vfs.f_blocks * vfs.f_frsize));
    printf("    Free Space: %s\n", format_size(vfs.f_bfree * vfs.f_frsize));
    printf("    Available Space: %s\n",
           format_size(vfs.f_bavail * vfs.f_frsize));
  } else {
    print_colored("Error: Failed to get disk space information\n", COLOR_RED);
  }
}
