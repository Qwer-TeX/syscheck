#include "cpu.h"
#include "disk.h"
#include "kernel.h"
#include "memory.h"
#include "network.h"
#include "processes.h"
#include "uptime.h"
#include "utils.h"

int main() {
  print_colored("System Health Check\n", COLOR_YELLOW);
  print_colored("====================\n", COLOR_YELLOW);
  check_cpu_usage();
  check_memory_usage();
  check_disk_space("/");
  check_kernel_version();
  check_system_uptime();
  check_top_processes();
  check_network_stats();

  return 0;
}
