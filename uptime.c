#include "uptime.h"
#include "utils.h"
#include <stdio.h>
#include <sys/sysinfo.h>

void check_system_uptime() {
  struct sysinfo info;
  if (sysinfo(&info) == 0) {
    unsigned long long uptime_seconds = info.uptime;
    unsigned long days = uptime_seconds / (24 * 3600);
    unsigned long hours = (uptime_seconds % (24 * 3600)) / 3600;
    unsigned long minutes = (uptime_seconds % 3600) / 60;
    unsigned long seconds = uptime_seconds % 60;

    print_colored("System Uptime:\n", COLOR_YELLOW);
    printf("  %lu days, %lu hours, %lu minutes, %lu seconds\n", days, hours,
           minutes, seconds);
  } else {
    print_colored("Error: Failed to get system uptime\n", COLOR_RED);
  }
}
