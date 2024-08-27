#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

const char *format_size(unsigned long long bytes) {
  static char buffer[64];
  const char *units[] = {"B", "KB", "MB", "GB", "TB"};
  int unit = 0;
  double value = bytes;

  while (value >= 1024 && unit < 4) {
    value /= 1024;
    unit++;
  }

  snprintf(buffer, sizeof(buffer), "%.2f %s", value, units[unit]);
  return buffer;
}

void print_colored(const char *message, const char *color) {
  printf("%s%s%s", color, message, COLOR_RESET);
}
