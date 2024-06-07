#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        std::cerr << "Error creating client socket\n";
        return 1;
    }

    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(client_socket, reinterpret_cast<sockaddr*>(&server_addr), sizeof(server_addr)) == -1) {
        std::cerr << "Error connecting to server\n";
        close(client_socket);
        return 1;
    }

    std::string message;
    std::cout << "Enter message: ";
    std::getline(std::cin, message);

    send(client_socket, message.c_str(), message.size(), 0);

    char buffer[1024];
    int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_received <= 0) {
        std::cerr << "Error receiving data from server\n";
        close(client_socket);
        return 1;
    }

    std::cout << "Reversed message: ";
    std::cout.write(buffer, bytes_received);
    std::cout << std::endl;

    close(client_socket);
    return 0;
}
