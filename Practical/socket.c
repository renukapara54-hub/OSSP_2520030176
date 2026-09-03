#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>

#define SOCKET_PATH "/tmp/my_socket"

int main()
{
    int client_fd;
    struct sockaddr_un address;
    char message[] = "Hello from client!";

    // Create socket
    client_fd = socket(AF_UNIX, SOCK_STREAM, 0);

    // Set socket address
    address.sun_family = AF_UNIX;
    strcpy(address.sun_path, SOCKET_PATH);

    // Connect to server
    connect(client_fd, (struct sockaddr *)&address, sizeof(address));

    // Send message
    write(client_fd, message, strlen(message) + 1);

    printf("Message sent to server.\n");

    close(client_fd);

    return 0;
}
