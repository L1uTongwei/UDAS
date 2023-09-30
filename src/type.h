#pragma once

struct accont{
    char username[16];
    unsigned long long password[8]; // SHA-512
    char preSalt[16], sufSalt[16];
    char metaData[400];
}; //sizeof(accont) = 512