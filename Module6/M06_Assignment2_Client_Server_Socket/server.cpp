/* Program name: server.cpp
* Author: Younghyun Lee
* Date last updated: 10/3/2024
* Purpose: Create a server socket and communicate
*/
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <map>

using namespace std;

// Enum definition for colors
enum Color {
    SUNSET,
    CHERRY,
    PHANTOM,
    TITANIUM,
    GEAUX,
    LIGHTNING,
    FOREST,
    MIDNIGHT,
    PASSION,
    ROOT,
    STORM,
    OCEAN,
    GLACIAL,
    INVALID
};

// Map for color names and format strings
map<Color, pair<string, string>> colorMap = {
    {SUNSET,    {"Sunset Orange",      "\033[1m\033[38;5;166m"}},
    {CHERRY,    {"Cherry Bomb",        "\033[1m\033[38;5;160m"}},
    {PHANTOM,   {"Phantom Black",      "\033[1m\033[38;5;0m\033[48;5;15m"}},
    {TITANIUM,  {"Titanium Silver",    "\033[1m\033[38;5;249m"}},
    {GEAUX,     {"Geaux Gold",         "\033[1m\033[38;5;179m"}},
    {LIGHTNING, {"Lightning Yellow",   "\033[1m\033[38;5;11m"}},
    {FOREST,    {"Forest Green",       "\033[1m\033[38;5;2m"}},
    {MIDNIGHT,  {"Midnight Blue",      "\033[1m\033[38;5;17m\033[48;5;15m"}},
    {PASSION,   {"Passion Purple",     "\033[1m\033[38;5;5m"}},
    {ROOT,      {"Root Beer",          "\033[1m\033[38;5;94m"}},
    {STORM,     {"Storm Surge",        "\033[1m\033[38;5;242m"}},
    {OCEAN,     {"Ocean's Rip",        "\033[1m\033[38;5;27m"}},
    {GLACIAL,   {"Glacial White",      "\033[1m\033[38;5;15m"}}
};

int main() {
    // Create a socket for the server
    int serverSock = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSock < 0) {
        cerr << "Failed to create socket." << endl;
        return -1;
    }

    // Bind the socket to a port
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(54000);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (::bind(serverSock, reinterpret_cast<sockaddr*>(&serverAddr), sizeof(serverAddr)) < 0) {
        cerr << "Failed to bind socket." << endl;
        close(serverSock);
        return -1;
    }

    // Start listening for connections
    if (listen(serverSock, SOMAXCONN) < 0) {
        cerr << "Failed to listen on socket." << endl;
        close(serverSock);
        return -1;
    }

    // Main loop to accept and handle connections
    while (true) {
        sockaddr_in clientAddr;
        socklen_t clientSize = sizeof(clientAddr);
        int clientSock = accept(serverSock, reinterpret_cast<sockaddr*>(&clientAddr), &clientSize);

        if (clientSock < 0) {
            cerr << "Failed to accept connection." << endl;
            continue;
        }

        int colorEnum;
        int bytesReceived = recv(clientSock, &colorEnum, sizeof(colorEnum), 0);
        if (bytesReceived <= 0) {
            cerr << "Failed to receive data from client." << endl;
            close(clientSock);
            continue;
        }

        cout << "Request Recieved\nreceiving: " << colorEnum << endl;

        // Check if the received enum is valid
        if (colorEnum >= 0 && colorEnum <= 12) {
            Color chosenColor = static_cast<Color>(colorEnum);
            auto colorData = colorMap[chosenColor];
            string response = colorData.second + colorData.first;

            // Send the response back to the client
            send(clientSock, response.c_str(), response.size(), 0);
            cout << "Server Response: " << response << endl;
        } else {
            string errorResponse = "Invalid color selection!";
            send(clientSock, errorResponse.c_str(), errorResponse.size(), 0);
            cout << "Invalid color selection received!" << endl;
        }

        close(clientSock); // Close the connection
    }

    close(serverSock);
    return 0;
}
