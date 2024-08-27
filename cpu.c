#include "cpu.h"
#include "utils.h"
#include <stdio.h>

void check_cpu_usage() {
  FILE *file = fopen("/proc/stat", "r");
  if (file) {
    char buffer[256];
    fgets(buffer, sizeof(buffer), file);
    print_colored("CPU Information:\n", COLOR_YELLOW);
    print_colored("Current CPU stats:\n", COLOR_GREEN);
    printf("  %s\n", buffer);
    fclose(file);
  } else {
    print_colored("Error: Failed to open /proc/stat\n", COLOR_RED);
  }
}
