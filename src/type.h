#pragma once

struct accont{
    char username[16];
    unsigned int password[64 / sizeof(unsigned int)]; // SHA-512
    char preSalt[16], sufSalt[16];
    unsigned int metaData[400 / sizeof(unsigned int)];
};