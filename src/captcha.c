#include <time.h>
#include "captcha.h"
unsigned long captcha_key(){
    unsigned long seed = clock();
    __asm__(
        "imull [%0], 16807\n\t"
        "andl [%0], 2147483647\n\t"
        : [sed]"p"(seed)
    );
    return seed;
}
char* captcha(){
    
}