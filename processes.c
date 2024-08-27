#include "processes.h"
#include "utils.h"
#include <stdio.h>

void check_top_processes() {
  print_colored("Top Processes by Memory Usage:\n", COLOR_YELLOW);
  printf("  Command\n");
  system("ps -eo pid,comm,%mem --sort=-%mem | head -n 10");
}
