#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/sched.h>

#define STACK_SIZE  8192

void child_process(void *arg) {
    printf("Child process with PID: %d\n", getpid());
    printf("Argument passed to child process: %s\n", (char *)arg);
}

int main() {
    char *arg = "Hello from child process!";
    char *child_stack = malloc(STACK_SIZE);  // Allocate stack for clone syscall

    // Using fork
    printf("Using fork:\n");
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child process created using fork with PID: %d\n", getpid());
        printf("Argument passed to child process: %s\n", arg);
        exit(0);
    } else if (pid > 0) {
        printf("Parent process with PID: %d\n", getpid());
        wait(NULL);
    } else {
        perror("fork");
        return 1;
    }

    // Using vfork
    printf("\nUsing vfork:\n");
    pid_t vpid = vfork();
    if (vpid == 0) {
        printf("Child process created using vfork with PID: %d\n", getpid());
        printf("Argument passed to child process: %s\n", arg);
        _exit(0);
    } else if (vpid > 0) {
        printf("Parent process with PID: %d\n", getpid());
        wait(NULL);
    } else {
        perror("vfork");
        return 1;
    }

    // Using clone
    printf("\nUsing clone:\n");
    pid_t cpid = clone(child_process, child_stack + STACK_SIZE, CLONE_VM | CLONE_FS | CLONE_FILES, arg);
    if (cpid == -1) {
        perror("clone");
        return 1;
    }

    printf("Parent process with PID: %d\n", getpid());
    wait(NULL);

    free(child_stack);
    return 0;
}

