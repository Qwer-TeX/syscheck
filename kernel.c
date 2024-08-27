#include "kernel.h"
#include "utils.h"
#include <stdio.h>

void check_kernel_version() {
  FILE *file = fopen("/proc/version", "r");
  if (file) {
    char buffer[256];
    fgets(buffer, sizeof(buffer), file);
    print_colored("Kernel Version Information:\n", COLOR_YELLOW);
    print_colored("Current kernel version:\n", COLOR_GREEN);
    printf("  %s\n", buffer);
    fclose(file);
  } else {
    print_colored("Error: Failed to open /proc/version\n", COLOR_RED);
  }
}
