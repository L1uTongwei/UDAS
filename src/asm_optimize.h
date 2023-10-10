#pragma once
#define memset(pointer, value, length) \
    __asm__( \
        "memset_loop:\n\t" \
            "movb [data + ecx - 1], val\n\t" \
            "loop memset_loop" \
        :: [data]"p"(pointer), [val]"r"(value), "c"(length) \
        :"memory" \
    )