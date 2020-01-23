#include <stdio.h> // printf
#include <stdlib.h> // Include exit()

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
    printf("  \e[31x\e[0m %s\n", message);
    exit(1);
  }
}

void equal_int(int a, int b, char* message) {
  if (a == b) {
    printf("  \e[32m✓\e[0m %s\n", message);
  } else {
    printf("  \e[31x\e[0m %s\n", message);
    printf("    %i != %i\n", a, b);
    exit(1);
  }
}
