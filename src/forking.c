enum ForkVariant {
  PARENT,
  CHILD,
  FAILURE,
};

struct ForkResult {
  enum ForkVariant variant;
  pid_t pid;
};

struct ForkResult forkProcess() {
  struct ForkResult result;
  // Perform a syscall to fork the process.
  result.pid = fork();

  // Determine the result variant based on the pid.
  if (result.pid == -1) {
    result.variant = FAILURE;
  } else if (result.pid > 0) {
    result.variant = PARENT;
  } else {
    result.variant = CHILD;
  }

  return result;
}

void test_forking() {
  struct ForkResult result = forkProcess();
  switch (result.variant) {
    case PARENT:
      describe("Test forking parent");
      // Parent process.
      ok(result.pid != getpid(), "We are in the parent process, and the child PID is not the same.");
      break;
    case CHILD:
      describe("Test forking child");
      // Child process.
      equal_uint(result.pid, 0, "In the child process, the pid is 0");
      exit(0);
      break;
    case FAILURE:
      ok(false, "The process failed to launch");
      break;
  }
}
