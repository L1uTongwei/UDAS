#include "crypt.h"
void SHA_512(unsigned long long buffer[8], char contents[48]){
    unsigned long long message[16], varbuf[8], w[80];
    __asm__(
        "pushq [text + 8 * 0]\n\t"
        "popq [msg + 8 * 0]\n\t"
        "pushq [text + 8 * 1]\n\t"
        "popq [msg + 8 * 1]\n\t"
        "pushq [text + 8 * 2]\n\t"
        "popq [msg + 8 * 2]\n\t"
        "pushq [text + 8 * 3]\n\t"
        "popq [msg + 8 * 3]\n\t"
        "pushq [text + 8 * 4]\n\t"
        "popq [msg + 8 * 4]\n\t"
        "pushq [text + 8 * 5]\n\t"
        "popq [msg + 8 * 5]\n\t"
        "movq [msg + 8 * 6], 0\n\t"
        "movq [msg + 8 * 7], 0\n\t"
        "movq [msg + 8 * 8], 0\n\t"
        "movq [msg + 8 * 9], 0\n\t"
        "movq [msg + 8 * 10], 0\n\t"
        "movq [msg + 8 * 11], 0\n\t"
        "movq [msg + 8 * 12], 0\n\t"
        "movq [msg + 8 * 13], 0\n\t"
        "movq [msg + 8 * 14], 0\n\t"
        "movq [msg + 8 * 15], 0\n\t"
        "orb [msg + 48], 0b10000000\n\t"
        "movb [msg + 112], 48\n\t"
        "movq [buf + 8 * 0], 0xcbbb9d5dc1059ed8\n\t"
        "movq [buf + 8 * 1], 0x629a292a367cd507\n\t"
        "movq [buf + 8 * 2], 0x9159015a3070dd17\n\t"
        "movq [buf + 8 * 3], 0x152fecd8f70e5939\n\t"
        "movq [buf + 8 * 4], 0x67332667ffc00b31\n\t"
        "movq [buf + 8 * 5], 0x8eb44a8768581511\n\t"
        "movq [buf + 8 * 6], 0xdb0c2e0d64f98fa7\n\t"
        "movq [buf + 8 * 7], 0x47b5481dbefa4fa4\n\t"
        "pushq [msg + 8 * 0]\n\t"
        "popq [w + 8 * 0]\n\t"
        "pushq [msg + 8 * 1]\n\t"
        "popq [w + 8 * 1]\n\t"
        "pushq [msg + 8 * 2]\n\t"
        "popq [w + 8 * 2]\n\t"
        "pushq [msg + 8 * 3]\n\t"
        "popq [w + 8 * 3]\n\t"
        "pushq [msg + 8 * 4]\n\t"
        "popq [w + 8 * 4]\n\t"
        "pushq [msg + 8 * 5]\n\t"
        "popq [w + 8 * 5]\n\t"
        "pushq [msg + 8 * 6]\n\t"
        "popq [w + 8 * 6]\n\t"
        "pushq [msg + 8 * 7]\n\t"
        "popq [w + 8 * 7]\n\t"
        "pushq [msg + 8 * 8]\n\t"
        "popq [w + 8 * 8]\n\t"
        "pushq [msg + 8 * 9]\n\t"
        "popq [w + 8 * 9]\n\t"
        "pushq [msg + 8 * 10]\n\t"
        "popq [w + 8 * 10]\n\t"
        "pushq [msg + 8 * 11]\n\t"
        "popq [w + 8 * 11]\n\t"
        "pushq [msg + 8 * 12]\n\t"
        "popq [w + 8 * 12]\n\t"
        "pushq [msg + 8 * 13]\n\t"
        "popq [w + 8 * 13]\n\t"
        "pushq [msg + 8 * 14]\n\t"
        "popq [w + 8 * 14]\n\t"
        "pushq [msg + 8 * 15]\n\t"
        "popq [w + 8 * 15]\n\t"
        // i = 16
        "movq r8, [w + 8 * 2]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 14]\n\t"
        SSIG1
        "addq [w + 8 * 16], rbx\n\t"
        "addq [w + 8 * 16], r8\n\t"
        "addq [w + 8 * 16], [w + 8 * 0]\n\t"
        "addq [w + 8 * 16], [w + 8 * 9]\n\t"
        // i = 17
        "movq r8, [w + 8 * 3]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 15]\n\t"
        SSIG1
        "addq [w + 8 * 17], rbx\n\t"
        "addq [w + 8 * 17], r8\n\t"
        "addq [w + 8 * 17], [w + 8 * 1]\n\t"
        "addq [w + 8 * 17], [w + 8 * 10]\n\t"
        // i = 18
        "movq r8, [w + 8 * 4]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 16]\n\t"
        SSIG1
        "addq [w + 8 * 18], rbx\n\t"
        "addq [w + 8 * 18], r8\n\t"
        "addq [w + 8 * 18], [w + 8 * 2]\n\t"
        "addq [w + 8 * 18], [w + 8 * 11]\n\t"
        // i = 19
        "movq r8, [w + 8 * 5]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 17]\n\t"
        SSIG1
        "addq [w + 8 * 19], rbx\n\t"
        "addq [w + 8 * 19], r8\n\t"
        "addq [w + 8 * 19], [w + 8 * 3]\n\t"
        "addq [w + 8 * 19], [w + 8 * 12]\n\t"
        // i = 20
        "movq r8, [w + 8 * 6]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 18]\n\t"
        SSIG1
        "addq [w + 8 * 20], rbx\n\t"
        "addq [w + 8 * 20], r8\n\t"
        "addq [w + 8 * 20], [w + 8 * 4]\n\t"
        "addq [w + 8 * 20], [w + 8 * 13]\n\t"
        // i = 21
        "movq r8, [w + 8 * 7]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 19]\n\t"
        SSIG1
        "addq [w + 8 * 21], rbx\n\t"
        "addq [w + 8 * 21], r8\n\t"
        "addq [w + 8 * 21], [w + 8 * 5]\n\t"
        "addq [w + 8 * 21], [w + 8 * 14]\n\t"
        // i = 22
        "movq r8, [w + 8 * 8]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 20]\n\t"
        SSIG1
        "addq [w + 8 * 22], rbx\n\t"
        "addq [w + 8 * 22], r8\n\t"
        "addq [w + 8 * 22], [w + 8 * 6]\n\t"
        "addq [w + 8 * 22], [w + 8 * 15]\n\t"
        // i = 23
        "movq r8, [w + 8 * 9]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 21]\n\t"
        SSIG1
        "addq [w + 8 * 23], rbx\n\t"
        "addq [w + 8 * 23], r8\n\t"
        "addq [w + 8 * 23], [w + 8 * 7]\n\t"
        "addq [w + 8 * 23], [w + 8 * 16]\n\t"
        // i = 24
        "movq r8, [w + 8 * 10]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 22]\n\t"
        SSIG1
        "addq [w + 8 * 24], rbx\n\t"
        "addq [w + 8 * 24], r8\n\t"
        "addq [w + 8 * 24], [w + 8 * 8]\n\t"
        "addq [w + 8 * 24], [w + 8 * 17]\n\t"
        // i = 25
        "movq r8, [w + 8 * 11]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 23]\n\t"
        SSIG1
        "addq [w + 8 * 25], rbx\n\t"
        "addq [w + 8 * 25], r8\n\t"
        "addq [w + 8 * 25], [w + 8 * 9]\n\t"
        "addq [w + 8 * 25], [w + 8 * 18]\n\t"
        // i = 26
        "movq r8, [w + 8 * 12]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 24]\n\t"
        SSIG1
        "addq [w + 8 * 26], rbx\n\t"
        "addq [w + 8 * 26], r8\n\t"
        "addq [w + 8 * 26], [w + 8 * 10]\n\t"
        "addq [w + 8 * 26], [w + 8 * 19]\n\t"
        // i = 27
        "movq r8, [w + 8 * 13]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 25]\n\t"
        SSIG1
        "addq [w + 8 * 27], rbx\n\t"
        "addq [w + 8 * 27], r8\n\t"
        "addq [w + 8 * 27], [w + 8 * 11]\n\t"
        "addq [w + 8 * 27], [w + 8 * 20]\n\t"
        // i = 28
        "movq r8, [w + 8 * 14]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 26]\n\t"
        SSIG1
        "addq [w + 8 * 28], rbx\n\t"
        "addq [w + 8 * 28], r8\n\t"
        "addq [w + 8 * 28], [w + 8 * 12]\n\t"
        "addq [w + 8 * 28], [w + 8 * 21]\n\t"
        // i = 29
        "movq r8, [w + 8 * 15]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 27]\n\t"
        SSIG1
        "addq [w + 8 * 29], rbx\n\t"
        "addq [w + 8 * 29], r8\n\t"
        "addq [w + 8 * 29], [w + 8 * 13]\n\t"
        "addq [w + 8 * 29], [w + 8 * 22]\n\t"
        // i = 30
        "movq r8, [w + 8 * 16]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 28]\n\t"
        SSIG1
        "addq [w + 8 * 30], rbx\n\t"
        "addq [w + 8 * 30], r8\n\t"
        "addq [w + 8 * 30], [w + 8 * 14]\n\t"
        "addq [w + 8 * 30], [w + 8 * 23]\n\t"
        // i = 31
        "movq r8, [w + 8 * 17]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 29]\n\t"
        SSIG1
        "addq [w + 8 * 31], rbx\n\t"
        "addq [w + 8 * 31], r8\n\t"
        "addq [w + 8 * 31], [w + 8 * 15]\n\t"
        "addq [w + 8 * 31], [w + 8 * 24]\n\t"
        // i = 32
        "movq r8, [w + 8 * 18]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 30]\n\t"
        SSIG1
        "addq [w + 8 * 32], rbx\n\t"
        "addq [w + 8 * 32], r8\n\t"
        "addq [w + 8 * 32], [w + 8 * 16]\n\t"
        "addq [w + 8 * 32], [w + 8 * 25]\n\t"
        // i = 33
        "movq r8, [w + 8 * 19]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 31]\n\t"
        SSIG1
        "addq [w + 8 * 33], rbx\n\t"
        "addq [w + 8 * 33], r8\n\t"
        "addq [w + 8 * 33], [w + 8 * 17]\n\t"
        "addq [w + 8 * 33], [w + 8 * 26]\n\t"
        // i = 34
        "movq r8, [w + 8 * 20]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 32]\n\t"
        SSIG1
        "addq [w + 8 * 34], rbx\n\t"
        "addq [w + 8 * 34], r8\n\t"
        "addq [w + 8 * 34], [w + 8 * 18]\n\t"
        "addq [w + 8 * 34], [w + 8 * 27]\n\t"
        // i = 35
        "movq r8, [w + 8 * 21]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 33]\n\t"
        SSIG1
        "addq [w + 8 * 35], rbx\n\t"
        "addq [w + 8 * 35], r8\n\t"
        "addq [w + 8 * 35], [w + 8 * 19]\n\t"
        "addq [w + 8 * 35], [w + 8 * 28]\n\t"
        // i = 36
        "movq r8, [w + 8 * 22]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 34]\n\t"
        SSIG1
        "addq [w + 8 * 36], rbx\n\t"
        "addq [w + 8 * 36], r8\n\t"
        "addq [w + 8 * 36], [w + 8 * 20]\n\t"
        "addq [w + 8 * 36], [w + 8 * 29]\n\t"
        // i = 37
        "movq r8, [w + 8 * 23]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 35]\n\t"
        SSIG1
        "addq [w + 8 * 37], rbx\n\t"
        "addq [w + 8 * 37], r8\n\t"
        "addq [w + 8 * 37], [w + 8 * 21]\n\t"
        "addq [w + 8 * 37], [w + 8 * 30]\n\t"
        // i = 38
        "movq r8, [w + 8 * 24]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 36]\n\t"
        SSIG1
        "addq [w + 8 * 38], rbx\n\t"
        "addq [w + 8 * 38], r8\n\t"
        "addq [w + 8 * 38], [w + 8 * 22]\n\t"
        "addq [w + 8 * 38], [w + 8 * 31]\n\t"
        // i = 39
        "movq r8, [w + 8 * 25]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 37]\n\t"
        SSIG1
        "addq [w + 8 * 39], rbx\n\t"
        "addq [w + 8 * 39], r8\n\t"
        "addq [w + 8 * 39], [w + 8 * 23]\n\t"
        "addq [w + 8 * 39], [w + 8 * 32]\n\t"
        // i = 40
        "movq r8, [w + 8 * 26]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 38]\n\t"
        SSIG1
        "addq [w + 8 * 40], rbx\n\t"
        "addq [w + 8 * 40], r8\n\t"
        "addq [w + 8 * 40], [w + 8 * 24]\n\t"
        "addq [w + 8 * 40], [w + 8 * 33]\n\t"
        // i = 41
        "movq r8, [w + 8 * 27]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 39]\n\t"
        SSIG1
        "addq [w + 8 * 41], rbx\n\t"
        "addq [w + 8 * 41], r8\n\t"
        "addq [w + 8 * 41], [w + 8 * 25]\n\t"
        "addq [w + 8 * 41], [w + 8 * 34]\n\t"
        // i = 42
        "movq r8, [w + 8 * 28]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 40]\n\t"
        SSIG1
        "addq [w + 8 * 42], rbx\n\t"
        "addq [w + 8 * 42], r8\n\t"
        "addq [w + 8 * 42], [w + 8 * 26]\n\t"
        "addq [w + 8 * 42], [w + 8 * 35]\n\t"
        // i = 43
        "movq r8, [w + 8 * 29]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 41]\n\t"
        SSIG1
        "addq [w + 8 * 43], rbx\n\t"
        "addq [w + 8 * 43], r8\n\t"
        "addq [w + 8 * 43], [w + 8 * 27]\n\t"
        "addq [w + 8 * 43], [w + 8 * 36]\n\t"
        // i = 44
        "movq r8, [w + 8 * 30]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 42]\n\t"
        SSIG1
        "addq [w + 8 * 44], rbx\n\t"
        "addq [w + 8 * 44], r8\n\t"
        "addq [w + 8 * 44], [w + 8 * 28]\n\t"
        "addq [w + 8 * 44], [w + 8 * 37]\n\t"
        // i = 45
        "movq r8, [w + 8 * 31]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 43]\n\t"
        SSIG1
        "addq [w + 8 * 45], rbx\n\t"
        "addq [w + 8 * 45], r8\n\t"
        "addq [w + 8 * 45], [w + 8 * 29]\n\t"
        "addq [w + 8 * 45], [w + 8 * 38]\n\t"
        // i = 46
        "movq r8, [w + 8 * 32]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 44]\n\t"
        SSIG1
        "addq [w + 8 * 46], rbx\n\t"
        "addq [w + 8 * 46], r8\n\t"
        "addq [w + 8 * 46], [w + 8 * 30]\n\t"
        "addq [w + 8 * 46], [w + 8 * 39]\n\t"
        // i = 47
        "movq r8, [w + 8 * 33]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 45]\n\t"
        SSIG1
        "addq [w + 8 * 47], rbx\n\t"
        "addq [w + 8 * 47], r8\n\t"
        "addq [w + 8 * 47], [w + 8 * 31]\n\t"
        "addq [w + 8 * 47], [w + 8 * 40]\n\t"
        // i = 48
        "movq r8, [w + 8 * 34]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 46]\n\t"
        SSIG1
        "addq [w + 8 * 48], rbx\n\t"
        "addq [w + 8 * 48], r8\n\t"
        "addq [w + 8 * 48], [w + 8 * 32]\n\t"
        "addq [w + 8 * 48], [w + 8 * 41]\n\t"
        // i = 49
        "movq r8, [w + 8 * 35]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 47]\n\t"
        SSIG1
        "addq [w + 8 * 49], rbx\n\t"
        "addq [w + 8 * 49], r8\n\t"
        "addq [w + 8 * 49], [w + 8 * 33]\n\t"
        "addq [w + 8 * 49], [w + 8 * 42]\n\t"
        // i = 50
        "movq r8, [w + 8 * 36]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 48]\n\t"
        SSIG1
        "addq [w + 8 * 50], rbx\n\t"
        "addq [w + 8 * 50], r8\n\t"
        "addq [w + 8 * 50], [w + 8 * 34]\n\t"
        "addq [w + 8 * 50], [w + 8 * 43]\n\t"
        // i = 51
        "movq r8, [w + 8 * 37]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 49]\n\t"
        SSIG1
        "addq [w + 8 * 51], rbx\n\t"
        "addq [w + 8 * 51], r8\n\t"
        "addq [w + 8 * 51], [w + 8 * 35]\n\t"
        "addq [w + 8 * 51], [w + 8 * 44]\n\t"
        // i = 52
        "movq r8, [w + 8 * 38]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 50]\n\t"
        SSIG1
        "addq [w + 8 * 52], rbx\n\t"
        "addq [w + 8 * 52], r8\n\t"
        "addq [w + 8 * 52], [w + 8 * 36]\n\t"
        "addq [w + 8 * 52], [w + 8 * 45]\n\t"
        // i = 53
        "movq r8, [w + 8 * 39]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 51]\n\t"
        SSIG1
        "addq [w + 8 * 53], rbx\n\t"
        "addq [w + 8 * 53], r8\n\t"
        "addq [w + 8 * 53], [w + 8 * 37]\n\t"
        "addq [w + 8 * 53], [w + 8 * 46]\n\t"
        // i = 54
        "movq r8, [w + 8 * 40]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 52]\n\t"
        SSIG1
        "addq [w + 8 * 54], rbx\n\t"
        "addq [w + 8 * 54], r8\n\t"
        "addq [w + 8 * 54], [w + 8 * 38]\n\t"
        "addq [w + 8 * 54], [w + 8 * 47]\n\t"
        // i = 55
        "movq r8, [w + 8 * 41]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 53]\n\t"
        SSIG1
        "addq [w + 8 * 55], rbx\n\t"
        "addq [w + 8 * 55], r8\n\t"
        "addq [w + 8 * 55], [w + 8 * 39]\n\t"
        "addq [w + 8 * 55], [w + 8 * 48]\n\t"
        // i = 56
        "movq r8, [w + 8 * 42]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 54]\n\t"
        SSIG1
        "addq [w + 8 * 56], rbx\n\t"
        "addq [w + 8 * 56], r8\n\t"
        "addq [w + 8 * 56], [w + 8 * 40]\n\t"
        "addq [w + 8 * 56], [w + 8 * 49]\n\t"
        // i = 57
        "movq r8, [w + 8 * 43]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 55]\n\t"
        SSIG1
        "addq [w + 8 * 57], rbx\n\t"
        "addq [w + 8 * 57], r8\n\t"
        "addq [w + 8 * 57], [w + 8 * 41]\n\t"
        "addq [w + 8 * 57], [w + 8 * 50]\n\t"
        // i = 58
        "movq r8, [w + 8 * 44]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 56]\n\t"
        SSIG1
        "addq [w + 8 * 58], rbx\n\t"
        "addq [w + 8 * 58], r8\n\t"
        "addq [w + 8 * 58], [w + 8 * 42]\n\t"
        "addq [w + 8 * 58], [w + 8 * 51]\n\t"
        // i = 59
        "movq r8, [w + 8 * 45]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 57]\n\t"
        SSIG1
        "addq [w + 8 * 59], rbx\n\t"
        "addq [w + 8 * 59], r8\n\t"
        "addq [w + 8 * 59], [w + 8 * 43]\n\t"
        "addq [w + 8 * 59], [w + 8 * 52]\n\t"
        // i = 60
        "movq r8, [w + 8 * 46]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 58]\n\t"
        SSIG1
        "addq [w + 8 * 60], rbx\n\t"
        "addq [w + 8 * 60], r8\n\t"
        "addq [w + 8 * 60], [w + 8 * 44]\n\t"
        "addq [w + 8 * 60], [w + 8 * 53]\n\t"
        // i = 61
        "movq r8, [w + 8 * 47]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 59]\n\t"
        SSIG1
        "addq [w + 8 * 61], rbx\n\t"
        "addq [w + 8 * 61], r8\n\t"
        "addq [w + 8 * 61], [w + 8 * 45]\n\t"
        "addq [w + 8 * 61], [w + 8 * 54]\n\t"
        // i = 62
        "movq r8, [w + 8 * 48]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 60]\n\t"
        SSIG1
        "addq [w + 8 * 62], rbx\n\t"
        "addq [w + 8 * 62], r8\n\t"
        "addq [w + 8 * 62], [w + 8 * 46]\n\t"
        "addq [w + 8 * 62], [w + 8 * 55]\n\t"
        // i = 63
        "movq r8, [w + 8 * 49]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 61]\n\t"
        SSIG1
        "addq [w + 8 * 63], rbx\n\t"
        "addq [w + 8 * 63], r8\n\t"
        "addq [w + 8 * 63], [w + 8 * 47]\n\t"
        "addq [w + 8 * 63], [w + 8 * 56]\n\t"
        // i = 64
        "movq r8, [w + 8 * 50]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 62]\n\t"
        SSIG1
        "addq [w + 8 * 64], rbx\n\t"
        "addq [w + 8 * 64], r8\n\t"
        "addq [w + 8 * 64], [w + 8 * 48]\n\t"
        "addq [w + 8 * 64], [w + 8 * 57]\n\t"
        // i = 65
        "movq r8, [w + 8 * 51]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 63]\n\t"
        SSIG1
        "addq [w + 8 * 65], rbx\n\t"
        "addq [w + 8 * 65], r8\n\t"
        "addq [w + 8 * 65], [w + 8 * 49]\n\t"
        "addq [w + 8 * 65], [w + 8 * 58]\n\t"
        // i = 66
        "movq r8, [w + 8 * 52]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 64]\n\t"
        SSIG1
        "addq [w + 8 * 66], rbx\n\t"
        "addq [w + 8 * 66], r8\n\t"
        "addq [w + 8 * 66], [w + 8 * 50]\n\t"
        "addq [w + 8 * 66], [w + 8 * 59]\n\t"
        // i = 67
        "movq r8, [w + 8 * 53]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 65]\n\t"
        SSIG1
        "addq [w + 8 * 67], rbx\n\t"
        "addq [w + 8 * 67], r8\n\t"
        "addq [w + 8 * 67], [w + 8 * 51]\n\t"
        "addq [w + 8 * 67], [w + 8 * 60]\n\t"
        // i = 68
        "movq r8, [w + 8 * 54]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 66]\n\t"
        SSIG1
        "addq [w + 8 * 68], rbx\n\t"
        "addq [w + 8 * 68], r8\n\t"
        "addq [w + 8 * 68], [w + 8 * 52]\n\t"
        "addq [w + 8 * 68], [w + 8 * 61]\n\t"
        // i = 69
        "movq r8, [w + 8 * 55]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 67]\n\t"
        SSIG1
        "addq [w + 8 * 69], rbx\n\t"
        "addq [w + 8 * 69], r8\n\t"
        "addq [w + 8 * 69], [w + 8 * 53]\n\t"
        "addq [w + 8 * 69], [w + 8 * 62]\n\t"
        // i = 70
        "movq r8, [w + 8 * 56]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 68]\n\t"
        SSIG1
        "addq [w + 8 * 70], rbx\n\t"
        "addq [w + 8 * 70], r8\n\t"
        "addq [w + 8 * 70], [w + 8 * 54]\n\t"
        "addq [w + 8 * 70], [w + 8 * 63]\n\t"
        // i = 71
        "movq r8, [w + 8 * 57]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 69]\n\t"
        SSIG1
        "addq [w + 8 * 71], rbx\n\t"
        "addq [w + 8 * 71], r8\n\t"
        "addq [w + 8 * 71], [w + 8 * 55]\n\t"
        "addq [w + 8 * 71], [w + 8 * 64]\n\t"
        // i = 72
        "movq r8, [w + 8 * 58]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 70]\n\t"
        SSIG1
        "addq [w + 8 * 72], rbx\n\t"
        "addq [w + 8 * 72], r8\n\t"
        "addq [w + 8 * 72], [w + 8 * 56]\n\t"
        "addq [w + 8 * 72], [w + 8 * 65]\n\t"
        // i = 73
        "movq r8, [w + 8 * 59]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 71]\n\t"
        SSIG1
        "addq [w + 8 * 73], rbx\n\t"
        "addq [w + 8 * 73], r8\n\t"
        "addq [w + 8 * 73], [w + 8 * 57]\n\t"
        "addq [w + 8 * 73], [w + 8 * 66]\n\t"
        // i = 74
        "movq r8, [w + 8 * 60]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 72]\n\t"
        SSIG1
        "addq [w + 8 * 74], rbx\n\t"
        "addq [w + 8 * 74], r8\n\t"
        "addq [w + 8 * 74], [w + 8 * 58]\n\t"
        "addq [w + 8 * 74], [w + 8 * 67]\n\t"
        // i = 75
        "movq r8, [w + 8 * 61]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 73]\n\t"
        SSIG1
        "addq [w + 8 * 75], rbx\n\t"
        "addq [w + 8 * 75], r8\n\t"
        "addq [w + 8 * 75], [w + 8 * 59]\n\t"
        "addq [w + 8 * 75], [w + 8 * 68]\n\t"
        // i = 76
        "movq r8, [w + 8 * 62]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 74]\n\t"
        SSIG1
        "addq [w + 8 * 76], rbx\n\t"
        "addq [w + 8 * 76], r8\n\t"
        "addq [w + 8 * 76], [w + 8 * 60]\n\t"
        "addq [w + 8 * 76], [w + 8 * 69]\n\t"
        // i = 77
        "movq r8, [w + 8 * 63]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 75]\n\t"
        SSIG1
        "addq [w + 8 * 77], rbx\n\t"
        "addq [w + 8 * 77], r8\n\t"
        "addq [w + 8 * 77], [w + 8 * 61]\n\t"
        "addq [w + 8 * 77], [w + 8 * 70]\n\t"
        // i = 78
        "movq r8, [w + 8 * 64]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 76]\n\t"
        SSIG1
        "addq [w + 8 * 78], rbx\n\t"
        "addq [w + 8 * 78], r8\n\t"
        "addq [w + 8 * 78], [w + 8 * 62]\n\t"
        "addq [w + 8 * 78], [w + 8 * 71]\n\t"
        // i = 79
        "movq r8, [w + 8 * 65]\n\t"
        SSIG0
        "mov rbx, r8\n\t"
        "movq r8, [w + 8 * 77]\n\t"
        SSIG1
        "addq [w + 8 * 79], rbx\n\t"
        "addq [w + 8 * 79], r8\n\t"
        "addq [w + 8 * 79], [w + 8 * 63]\n\t"
        "addq [w + 8 * 79], [w + 8 * 72]\n\t"
        "movq [vbuf + 8 * 0], 0xcbbb9d5dc1059ed8\n\t"
        "movq [vbuf + 8 * 1], 0x629a292a367cd507\n\t"
        "movq [vbuf + 8 * 2], 0x9159015a3070dd17\n\t"
        "movq [vbuf + 8 * 3], 0x152fecd8f70e5939\n\t"
        "movq [vbuf + 8 * 4], 0x67332667ffc00b31\n\t"
        "movq [vbuf + 8 * 5], 0x8eb44a8768581511\n\t"
        "movq [vbuf + 8 * 6], 0xdb0c2e0d64f98fa7\n\t"
        "movq [vbuf + 8 * 7], 0x47b5481dbefa4fa4\n\t"
        // i = 0
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 0]\n\t"
        "addq r8, [w + 0]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 1
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 1]\n\t"
        "addq r8, [w + 1]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 2
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 2]\n\t"
        "addq r8, [w + 2]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 3
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 3]\n\t"
        "addq r8, [w + 3]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 4
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 4]\n\t"
        "addq r8, [w + 4]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 5
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 5]\n\t"
        "addq r8, [w + 5]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 6
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 6]\n\t"
        "addq r8, [w + 6]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 7
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 7]\n\t"
        "addq r8, [w + 7]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 8
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 8]\n\t"
        "addq r8, [w + 8]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 9
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 9]\n\t"
        "addq r8, [w + 9]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 10
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 10]\n\t"
        "addq r8, [w + 10]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 11
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 11]\n\t"
        "addq r8, [w + 11]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 12
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 12]\n\t"
        "addq r8, [w + 12]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 13
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 13]\n\t"
        "addq r8, [w + 13]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 14
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 14]\n\t"
        "addq r8, [w + 14]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 15
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 15]\n\t"
        "addq r8, [w + 15]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 16
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 16]\n\t"
        "addq r8, [w + 16]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 17
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 17]\n\t"
        "addq r8, [w + 17]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 18
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 18]\n\t"
        "addq r8, [w + 18]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 19
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 19]\n\t"
        "addq r8, [w + 19]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 20
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 20]\n\t"
        "addq r8, [w + 20]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 21
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 21]\n\t"
        "addq r8, [w + 21]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 22
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 22]\n\t"
        "addq r8, [w + 22]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 23
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 23]\n\t"
        "addq r8, [w + 23]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 24
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 24]\n\t"
        "addq r8, [w + 24]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 25
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 25]\n\t"
        "addq r8, [w + 25]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 26
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 26]\n\t"
        "addq r8, [w + 26]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 27
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 27]\n\t"
        "addq r8, [w + 27]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 28
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 28]\n\t"
        "addq r8, [w + 28]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 29
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 29]\n\t"
        "addq r8, [w + 29]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 30
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 30]\n\t"
        "addq r8, [w + 30]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 31
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 31]\n\t"
        "addq r8, [w + 31]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 32
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 32]\n\t"
        "addq r8, [w + 32]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 33
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 33]\n\t"
        "addq r8, [w + 33]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 34
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 34]\n\t"
        "addq r8, [w + 34]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 35
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 35]\n\t"
        "addq r8, [w + 35]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 36
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 36]\n\t"
        "addq r8, [w + 36]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 37
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 37]\n\t"
        "addq r8, [w + 37]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 38
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 38]\n\t"
        "addq r8, [w + 38]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 39
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 39]\n\t"
        "addq r8, [w + 39]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 40
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 40]\n\t"
        "addq r8, [w + 40]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 41
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 41]\n\t"
        "addq r8, [w + 41]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 42
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 42]\n\t"
        "addq r8, [w + 42]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 43
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 43]\n\t"
        "addq r8, [w + 43]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 44
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 44]\n\t"
        "addq r8, [w + 44]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 45
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 45]\n\t"
        "addq r8, [w + 45]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 46
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 46]\n\t"
        "addq r8, [w + 46]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 47
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 47]\n\t"
        "addq r8, [w + 47]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 48
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 48]\n\t"
        "addq r8, [w + 48]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 49
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 49]\n\t"
        "addq r8, [w + 49]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 50
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 50]\n\t"
        "addq r8, [w + 50]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 51
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 51]\n\t"
        "addq r8, [w + 51]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 52
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 52]\n\t"
        "addq r8, [w + 52]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 53
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 53]\n\t"
        "addq r8, [w + 53]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 54
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 54]\n\t"
        "addq r8, [w + 54]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 55
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 55]\n\t"
        "addq r8, [w + 55]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 56
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 56]\n\t"
        "addq r8, [w + 56]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 57
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 57]\n\t"
        "addq r8, [w + 57]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 58
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 58]\n\t"
        "addq r8, [w + 58]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 59
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 59]\n\t"
        "addq r8, [w + 59]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 60
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 60]\n\t"
        "addq r8, [w + 60]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 61
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 61]\n\t"
        "addq r8, [w + 61]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 62
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 62]\n\t"
        "addq r8, [w + 62]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 63
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 63]\n\t"
        "addq r8, [w + 63]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 64
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 64]\n\t"
        "addq r8, [w + 64]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 65
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 65]\n\t"
        "addq r8, [w + 65]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 66
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 66]\n\t"
        "addq r8, [w + 66]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 67
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 67]\n\t"
        "addq r8, [w + 67]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 68
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 68]\n\t"
        "addq r8, [w + 68]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 69
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 69]\n\t"
        "addq r8, [w + 69]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 70
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 70]\n\t"
        "addq r8, [w + 70]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 71
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 71]\n\t"
        "addq r8, [w + 71]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 72
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 72]\n\t"
        "addq r8, [w + 72]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 73
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 73]\n\t"
        "addq r8, [w + 73]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 74
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 74]\n\t"
        "addq r8, [w + 74]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 75
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 75]\n\t"
        "addq r8, [w + 75]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 76
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 76]\n\t"
        "addq r8, [w + 76]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 77
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 77]\n\t"
        "addq r8, [w + 77]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 78
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 78]\n\t"
        "addq r8, [w + 78]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        // i = 79
        "mov r8, [vbuf + 8 * 4]\n\t"
        BSIG1
        "mov rbx, r8\n\t"
        "movq r8, [vbuf + 8 * 4]\n\t"
        "movq r9, [vbuf + 8 * 5]\n\t"
        "movq r10, [vbuf + 8 * 6]\n\t"
        CH
        "addq r8, [vbuf + 8 * 7]\n\t"
        "add r8, rbx\n\t"
        "addq r8, [K + 79]\n\t"
        "addq r8, [w + 79]\n\t"
        "mov rbx, r8\n\t" // temp1
        "addq r8, [vbuf + 8 * 0]\n\t"
        BSIG0
        "mov rcx, r8\n\t" // S0
        "movq r8, [vbuf + 8 * 0]\n\t"
        "movq r9, [vbuf + 8 * 1]\n\t"
        "movq r10, [vbuf + 8 * 2]\n\t"
        MAJ
        "add r8, rcx\n\t" // temp2
        "pushq [vbuf + 6]\n\t"
        "popq [vbuf + 7]\n\t"
        "pushq [vbuf + 5]\n\t"
        "popq [vbuf + 6]\n\t"
        "pushq [vbuf + 4]\n\t"
        "popq [vbuf + 5]\n\t"
        "movq rdx, [vbuf + 3]\n\t"
        "add rdx, rbx\n\t"
        "pushq rdx\n\t"
        "popq [vbuf + 4]\n\t"
        "pushq [vbuf + 2]\n\t"
        "popq [vbuf + 3]\n\t"
        "pushq [vbuf + 1]\n\t"
        "popq [vbuf + 2]\n\t"
        "pushq [vbuf + 0]\n\t"
        "popq [vbuf + 1]\n\t"
        "add rcx, rbx\n\t"
        "pushq rcx\n\t"
        "popq [vbuf + 0]\n\t"
        "addq [buf + 8 * 0], [vbuf + 8 * 0]\n\t"
        "addq [buf + 8 * 1], [vbuf + 8 * 1]\n\t"
        "addq [buf + 8 * 2], [vbuf + 8 * 2]\n\t"
        "addq [buf + 8 * 3], [vbuf + 8 * 3]\n\t"
        "addq [buf + 8 * 4], [vbuf + 8 * 4]\n\t"
        "addq [buf + 8 * 5], [vbuf + 8 * 5]\n\t"
        "addq [buf + 8 * 6], [vbuf + 8 * 6]\n\t"
        "addq [buf + 8 * 7], [vbuf + 8 * 7]\n\t"
        :: [msg]"p"(message), [text]"p"(contents), [buf]"p"(buffer), [vbuf]"p"(varbuf), [K]"p"(SHA_K), [w]"p"(w), 
           "ax"(0), "rbx"(0), "rcx"(0), "rdx"(0), "r8"(0), "r9"(0), "r10"(0), "r11"(0) 
        :"memory"
    );
}