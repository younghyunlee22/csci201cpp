/* Program name: client.cpp
* Author: Younghyun Lee
* Date last updated: 10/3/2024
* Purpose: Create a client server and communicate
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

int main() {
    // Create a TCP socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        cerr << "Failed to create socket." << endl;
        return -1;
    }

    // Create a sockaddr_in structure to specify server details
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(54000); // Server port
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr); // Localhost address

    // Connect to the server
    if (connect(sock, reinterpret_cast<sockaddr*>(&serverAddr), sizeof(serverAddr)) < 0) {
        cerr << "Failed to connect to the server." << endl;
        close(sock);
        return -1;
    }

    // Menu for selecting color
    map<int, string> colorMenu = {
        {0, "Sunset Orange"},
        {1, "Cherry Bomb"},
        {2, "Phantom Black"},
        {3, "Titanium Silver"},
        {4, "Geaux Gold"},
        {5, "Lightning Yellow"},
        {6, "Forest Green"},
        {7, "Midnight Blue"},
        {8, "Passion Purple"},
        {9, "Root Beer"},
        {10, "Storm Surge"},
        {11, "Ocean's Rip"},
        {12, "Glacial White"}
    };

    // Display menu
    cout << "choose a color from the list below: " << endl;
    for (const auto& color : colorMenu) {
        cout << color.first << ". " << color.second << endl;
    }

    // Get user input
    int userInput;
    cin >> userInput;

    while (userInput < 0 || userInput > 12) {
        cout << "Invalid input. Please try again." << endl;
        cin >> userInput;
    }

    // Send the chosen color enum to the server
    send(sock, &userInput, sizeof(userInput), 0);

    // Buffer to receive the server's response
    char buf[4096];
    memset(buf, 0, 4096);

    // Receive the server's response
    int bytesReceived = recv(sock, buf, 4096, 0);
    if (bytesReceived > 0) {
        cout << "Server Response: " << string(buf, 0, bytesReceived) << endl;
    }

    // Close the socket
    close(sock);

    return 0;
}
