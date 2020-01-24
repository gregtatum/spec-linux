/**
 * This file contains the base includes that can be added to any file. It imports some
 * of the basic system libraries that are useful, as well as the test suite.
 */
#include <sys/types.h> // Contains some base types
#include <sys/syscall.h>
#include <unistd.h> // Contains the syscall interfaces
#include <stdbool.h>
#include <stdio.h> // printf
#include <stdlib.h> // Include exit()

// The test suite functions.
void describe(char* message);
void ok(bool assertion, char* message);
void equal_int(int a, int b, char* message);
void equal_uint(uint a, uint b, char* message);

// The actual test files.
void test_forking();
