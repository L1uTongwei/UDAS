#include "network.h"

int startServer(struct sockaddr_in addr, int port, int mode, int backlog, int(*callback)(int, struct sockaddr_in*, int, char*)){
    int sockfd = socket(AF_INET, mode, 0);
    #ifndef _WIN32
        if(sockfd == -1){
            printf("Socket Error: %s (Error Code: %d)\n", strerror(errno), errno);
            exit(errno);
        }
    #else
        if(sockfd == INVALID_SOCKET){
            printf("Socket Error: (Error Code: %d)\n", WSAGetLastError());
            WSACleanup();
            exit(WSAGetLastError());
        }
    #endif
    int bind_status = bind(sockfd, (struct sockaddr*)&addr, sizeof(addr));
    #ifndef _WIN32
        if(bind_status == -1){
            printf("Bind Error: %s (Error Code: %d)\n", strerror(errno), errno);
            exit(errno);
        }
    #else
        if(bind_status == SOCKET_ERROR){
            printf("Bind Error: (Error Code: %d)\n", WSAGetLastError());
            WSACleanup();
            exit(WSAGetLastError());
        }
    #endif
    int listen_status = listen(sockfd, backlog);
    #ifndef _WIN32
        if(listen_status == -1){
            printf("Listen Error: %s (Error Code: %d)\n", strerror(errno), errno);
            exit(errno);
        }
    #else
        if(listen_status == SOCKET_ERROR){
            printf("Listen Error: (Error Code: %d)\n", WSAGetLastError());
            WSACleanup();
            exit(WSAGetLastError());
        }
    #endif
    char buf[438]; // Receive Buffer
    while(1){
        struct sockaddr_in clientAddr;
        int connfd = accept(sockfd, (struct sockaddr*)&clientAddr, sizeof(clientAddr));
        #ifndef _WIN32
            if(connfd == -1) continue;
        #else
            if(connfd == SOCKET_ERROR) continue;
        #endif
        int n = recv(connfd, buf, 437, 0);
        buf[15] = buf[31] = buf[36] = buf[437] = '\0';
        callback(sockfd, &clientAddr, n, buf);
        close(connfd);
    }
    #ifndef _WIN32
        close(sockfd);
    #else
        closesocket(sockfd);
    #endif
}