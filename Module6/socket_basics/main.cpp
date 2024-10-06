#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

/*
ntohs -->> network to host short
*/

int  main(){
    // we don't need to initialize socket on macOS

    // Server -> 1. Create a TCP socket for incoming connections
    // socket(domain, type, protocol)
    // domain: AF_INET (IPv4 protocol), AF_INET6 (IPv6 protocol)
    // type: SOCK_STREAM (TCP), SOCK_DGRAM (UDP)
    // protocol: IPPROTO_TCP, IPPROTO_UDP or 0 for default
    int servSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(servSock < 0){
        std::cerr << "socket() failed"<< std::endl;
        return -1;
    }

    // Server -> 2. Assign a port to socket
    sockaddr_in echoServAddr;
    echoServAddr.sin_family = AF_INET;
    echoServAddr.sin_port = htons(54000); // Set port 54000 as the port to listen (echo server port)
    echoServAddr.sin_addr.s_addr = htons(INADDR_ANY);
    // Casts echoServAddr from sockaddr_in* to sockaddr* for compatibility with the bind() function.
    if (bind(servSock, reinterpret_cast<sockaddr*>(&echoServAddr), sizeof(echoServAddr)) < 0) {
        std::cerr << "bind() failed"<< std::endl;
        return -1;
    }

    // Server -> 3. Set socket to listen
    // Mark the socket so it will listen for incoming connections
    if(listen(servSock, SOMAXCONN) < 0 ) {
        std::cerr << "listen() failed"<< std::endl;
        return -1;
    };

    // Server -> 4. Repeatedly:
        // a. Accept new connection
        // b. Communicate
        // c. Close the connection

    sockaddr_in echoClntAddr;
    socklen_t clntLen = sizeof(echoClntAddr);

    // a. Accept new connection
    int clntSock = accept(servSock, reinterpret_cast<sockaddr*>(&echoClntAddr), &clntLen);
    if (clntSock < 0)
    {
        std::cerr << "accept() failed" << std::endl;
        return -1;
    }

    char host[NI_MAXHOST]; // Client's remote name
    char service[NI_MAXHOST]; // Service (i.e. port) the client is connected on.

    memset(host, 0, NI_MAXHOST); // ZeroMemory(host, NI_MAXHOST);
    memset(service, 0, NI_MAXHOST);

    if (getnameinfo(reinterpret_cast<sockaddr*>(&echoClntAddr), sizeof(echoClntAddr), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {
        std::cout << host << " connected on port " << service << std::endl;
    } else {
        inet_ntop(AF_INET, &echoClntAddr.sin_addr, host, NI_MAXHOST);
        std::cout << host << " connected on port " << ntohs(echoClntAddr.sin_port) << std::endl;
    }

    // b. Communicate (while loop: accept and echo message back to client)
    char buf[4096];

    while (true) {
        memset(buf, 0, 4096);
        // wait for client to send data
        int bytesReceived = recv(clntSock, buf, 4096, 0);
        if (bytesReceived < 0)
        {
            std::cerr << "recv() failed." << std::endl;
            break;
        }
        if (bytesReceived == 0) { // if zero bytes received
            std::cout << "Client disconnected..." << std::endl;
            break;
        }
        std::cout << "message: " << std::string(buf, 0, bytesReceived) << std::endl;
        // Echo message back to client
        send(clntSock, buf, bytesReceived + 1, 0);
    }

    // c. Close the connection
    close(clntSock);
    close(servSock);

    // No need to shut down socket on macOS
    return 0;
}
