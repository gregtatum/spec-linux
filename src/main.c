#include <stdbool.h>
#include <sys/types.h> // Contains some base types
#include <sys/syscall.h>
#include <unistd.h> // Contains the syscall interfaces
#include "./test-utils.c"

void test_basic_system_call() {
  describe("Test basic system calls.");

  int pid = getpid();
  ok(pid > 1, "getpid() is a syscall, it will be greater than 1.");

  equal_int(
    syscall(SYS_getpid),
    pid,
    "The PID can also be retrieved through the syscall interface."
  );
}

int main() {
  test_basic_system_call();
  printf("\n\n All tests pass!!");
  return 0;
}
