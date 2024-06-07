#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <thread>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void handle_client(int client_socket) {
    char buffer[1024];
    int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_received <= 0) {
        std::cerr << "Error receiving data from client\n";
        return;
    }

    std::string received_data(buffer, bytes_received);
    std::reverse(received_data.begin(), received_data.end());

    send(client_socket, received_data.c_str(), received_data.size(), 0);
    close(client_socket);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        std::cerr << "Error creating server socket\n";
        return 1;
    }

    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, reinterpret_cast<sockaddr*>(&server_addr), sizeof(server_addr)) == -1) {
        std::cerr << "Error binding socket\n";
        close(server_socket);
        return 1;
    }

    if (listen(server_socket, 10) == -1) {
        std::cerr << "Error listening on socket\n";
        close(server_socket);
        return 1;
    }

    std::cout << "Server listening on port 12345\n";

    while (true) {
        sockaddr_in client_addr;
        socklen_t client_addr_size = sizeof(client_addr);
        int client_socket = accept(server_socket, reinterpret_cast<sockaddr*>(&client_addr), &client_addr_size);
        if (client_socket == -1) {
            std::cerr << "Error accepting client connection\n";
            continue;
        }

        std::cout << "Client connected\n";
        std::thread(handle_client, client_socket).detach();
    }

    close(server_socket);
    return 0;
}
