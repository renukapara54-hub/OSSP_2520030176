#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <sys/wait.h>

int main(void)

{

    pid_t pid;

    int status;

    // Retrieve PATH variable

    char *path = getenv("PATH");

    if (path != NULL)

        printf("PATH = %s\n\n", path);

    else

        printf("PATH variable not found.\n");

    // Create child process

    pid = fork();

    if (pid < 0)

    {

        perror("fork failed");

        return 1;

    }

    if (pid == 0)

    {

        // Child process

        printf("Child: Running command...\n");

        execlp("echo", "echo", "Command executed successfully", NULL);

        perror("execlp failed");

        exit(1);

    }

    else

    {

        // Parent waits specifically for the child

        if (waitpid(pid, &status, 0) == -1)

        {

            perror("waitpid failed");

            return 1;

        }

        if (WIFEXITED(status))

        {

            printf("Parent: Child exited with status %d\n",

                   WEXITSTATUS(status));

        }

    }

    return 0;

}
