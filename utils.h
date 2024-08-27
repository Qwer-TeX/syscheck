#ifndef UTILS_H
#define UTILS_H

// ANSI escape codes for colors
#define COLOR_RESET "\033[0m"
#define COLOR_GREEN "\033[32m"
#define COLOR_RED "\033[31m"
#define COLOR_YELLOW "\033[33m"

// Function prototypes
const char *format_size(unsigned long long bytes);
void print_colored(const char *message, const char *color);

#endif // UTILS_H
