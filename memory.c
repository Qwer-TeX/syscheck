#include "memory.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_memory_usage() {
  FILE *file = fopen("/proc/meminfo", "r");
  if (file) {
    char buffer[256];
    unsigned long long total_mem = 0, free_mem = 0, available_mem = 0;
    print_colored("Memory Information:\n", COLOR_YELLOW);
    print_colored("Memory usage details:\n", COLOR_GREEN);
    while (fgets(buffer, sizeof(buffer), file)) {
      char *key = strtok(buffer, ":");
      char *value = strtok(NULL, ":");
      if (key && value) {
        unsigned long long mem_value = strtoull(value, NULL, 10);
        if (strstr(key, "MemTotal")) {
          total_mem = mem_value * 1024;
        } else if (strstr(key, "MemFree")) {
          free_mem = mem_value * 1024;
        } else if (strstr(key, "MemAvailable")) {
          available_mem = mem_value * 1024;
        }
      }
    }
    fclose(file);

    printf("  Total Memory: %s\n", format_size(total_mem));
    printf("  Free Memory: %s\n", format_size(free_mem));
    printf("  Available Memory: %s\n", format_size(available_mem));
  } else {
    print_colored("Error: Failed to open /proc/meminfo\n", COLOR_RED);
  }
}
