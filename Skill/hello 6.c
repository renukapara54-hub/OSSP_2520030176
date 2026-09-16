#include <stdio.h>

#include <unistd.h>

#include <sys/wait.h>

#include <stdlib.h>

int main(void)

{

    pid_t pid;

    printf("Parent process started.\n");

    pid = fork();

    if (pid < 0)

    {

        perror("fork failed");

        return 1;

    }

    if (pid == 0)

    {

        // Child process

        printf("Child process started.\n");

        execlp("echo", "echo", "Hello from child process!", NULL);

        // This runs only if execlp() fails

        perror("execlp failed");

        exit(1);

    }

    else

    {

        // Parent process

        wait(NULL);

        printf("Child process completed.\n");

    }

    return 0;

}
