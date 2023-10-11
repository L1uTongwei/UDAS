#include "trie.h"
#include "../asm_optimize.h"
short trie_init(struct trie* t, int size, short charset){
    int i = 0;
    if(charset != ALPHA_CHARSET && charset != FULL_CHARSET) return 1;
    if(t == NULL) t = malloc(sizeof(struct trie));
    memset(t, sizeof(struct trie), 0);
    t->next = malloc(size * 48 * sizeof(short*));
    t->data = malloc(size * 48 * sizeof(void*));
    for(i = 0; i < size * 48; i++){
        t->next[i] = malloc(charset * sizeof(short));
    }
    t->size = size, t->charset = charset, t->count = 0;
    return 0;
}
short trie_insert(struct trie* t, const char* s, void* data){
    short noffset = (t->charset == ALPHA_CHARSET) ? 'a' : 0;
    int p = 0;
    __asm__(
        "mov eax, 0\n\t" // p
        "mov ebx, 0\n\t" // i
        "mov ecx, 0\n\t" // s[i] - noffset
        "mov edx, 0\n\t" // temp
        "insertLoop:\n\t"
            "mov ecx, [s + ebx]\n\t"
            "sub ecx, noffset\n\t"
            "cmpb [nex * eax + ecx], 0\n\t"
            "jnz endAddNode\n\t"
            "addNode:\n\t"
                "incb [cnt]\n\t"
                "movb [nex * eax + ecx], edx\n\t"
                "movb edx, [cnt]\n\t"
            "endAddNode:\n\t"
            "mov eax, [nex * eax + ecx]\n\t"
            "inc ebx\n\t"
            "cmpb [s + ebx], '\0'\n\t"
            "jnz insertLoop\n\t"
        "mov outv, eax\n\t"
        : [outv]"=g"(p)
        : [str]"p"(s), [nex]"p"(t->next), [cnt]"m"(t->count), [no]"r"(noffset)
        : "eax", "ebx", "ecx", "edx", "memory"
    );
    t->data[p] = data;
}
void* trie_find(struct trie* t, const char* s){
    short noffset = (t->charset == ALPHA_CHARSET) ? 'a' : 0;
    int p = 0;
    __asm__(
        "mov eax, 0\n\t" // p
        "mov ebx, 0\n\t" // i
        "mov ecx, 0\n\t" // s[i] - noffset
        "mov edx, 0\n\t" // temp
        "insertLoop:\n\t"
            "mov ecx, [s + ebx]\n\t"
            "sub ecx, noffset\n\t"
            "cmpb [nex * eax + ecx], 0\n\t"
            "jnz found\n\t"
            "notFound:\n\t"
                "jmp goAway\n\t"
            "found:\n\t"
            "mov eax, [nex * eax + ecx]\n\t"
            "inc ebx\n\t"
            "cmpb [s + ebx], '\0'\n\t"
            "jnz insertLoop\n\t"
        "mov outv, eax\n\t"
        : [outv]"=g"(p)
        : [str]"p"(s), [nex]"p"(t->next), [cnt]"m"(t->count), [no]"r"(noffset)
        : "eax", "ebx", "ecx", "edx", "memory"
    );
    return t->data[p];
    __asm__("goAway:"); return NULL;
}
void trie_free(struct trie* t){
    int i = 0;
    for(i = 0; i < t->size * 48; i++){
        free(t->next[i]);
    }
    free(t->next);
    free(t->data);
    free(t);
}