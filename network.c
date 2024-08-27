#include "network.h"
#include "utils.h"
#include <stdio.h>

void check_network_stats() {
  print_colored("Network Statistics:\n", COLOR_YELLOW);
  printf("  Interface            RX bytes       TX bytes\n");
  system("netstat -i | awk 'NR>2 {print $1, $3, $9}'");
}
