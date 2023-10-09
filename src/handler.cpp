#include <string>
#include <unordered_map>
#include "type.h"
#include "handler.h"
#include "network.h"
#include "captcha.h"
std::unordered_map<std::string, unsigned long> Session;
extern "C"{
    int handler(int sockfd, struct sockaddr_in* clientAddr, int length, char* buf){
        switch(length){
            case 36: // captcha, just token
                Session[buf] = captcha_key();
                break;
            case 73: // login without metadata
                break;
            default: // register with metadata
                break;
        };
    }
}