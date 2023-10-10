#include <string.h>
#include "handler.h"
#include "../network/network.h"
#include "../captcha/captcha.h"

int handler(int sockfd, struct sockaddr_in* clientAddr, int length, char* buf){
    switch(length){
        case 36: // captcha, just token
            break;
        case 73: // login without metadata
            break;
        default: // register with metadata
            break;
    };
}