/**
 * This file contains the test suite implementation. The declarations are located
 * in the base.h file.
 */
#include "base.h"

// Useful colors:
// Reset: \e[0m
// Green: \e[32m
// Red: \e[31
// Bold: \e[1m

void describe(char* message) {
  printf("\n\e[1m%s\e[0m\n", message);
}

void ok(bool assertion, char* message) {
  if (assertion) {
    printf("  \e[32m✓\e[0m %s\n", message);
  } else {
    printf("  \e[31mx\e[0m %s\n", message);
    exit(1);
  }
}

void equal_int(int a, int b, char* message) {
  if (a == b) {
    printf("  \e[32m✓\e[0m %s\n", message);
  } else {
    printf("  \e[31mx %s\n", message);
    printf("    %i != %i\e[0m\n", a, b);
    exit(1);
  }
}

void equal_uint(uint a, uint b, char* message) {
  if (a == b) {
    printf("  \e[32m✓\e[0m %s\n", message);
  } else {
    printf("  \e[31mx %s\n", message);
    printf("    %u != %u\e[0m\n", a, b);
    exit(1);
  }
}
