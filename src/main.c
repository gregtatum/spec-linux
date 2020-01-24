#include "base.h"

void test_basic_system_call() {
  describe("Test basic system calls.");

  pid_t pid = getpid();
  ok(pid > 1, "getpid() is a syscall, it will be greater than 1.");

  equal_int(
    syscall(SYS_getpid),
    pid,
    "The PID can also be retrieved through the syscall interface."
  );

  equal_uint(
    SYS_getpid,
    // This looks like from the source code that it should be 20, but it's really 39?
    // 20,
    39,
    "The SYS_getpid maps to a real number that is defined in the source code."
  );

  equal_int(getppid(), 1, "The kernel launched this process which as a PID of 1.");

  // gettid() is not defined here, so just use the syscall.
  pid_t tid = syscall(SYS_gettid);
  equal_int(pid, tid, "The TID is the same as the PID in this single threaded app.");
}

int main() {
  // Run forking test first, as the child process runs in the same code path as the
  // parent process.
  test_forking();
  test_basic_system_call();
  return 0;
}
