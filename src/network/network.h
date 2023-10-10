#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#ifndef _WIN32
    #include <errno.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
#else
    #include <winsock.h>
#endif
#include <unistd.h>

inline int startServer(struct sockaddr_in addr, int port, int mode, int backlog, int(*callback)(int, struct sockaddr_in*, int, char*)) __attribute((always_inline));