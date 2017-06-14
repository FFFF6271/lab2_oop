#ifndef L2_OOP_LIB_MEM_H
#define L2_OOP_LIB_MEM_H

#define VECTORINA_ERROR_P "[VECTORINA ERROR]"

#define STRSZ(str) str, sizeof(str) - 1
#define STRLN(str) str, strlen(str)

#define SZ(str) sizeof(str) - 1

#define KiB * 1024
#define xassert(expr, text) do {                                        \
        if(!(expr))                                                     \
        {                                                               \
            printf(VECTORINA_ERROR_P" %s line: %d", text, __LINE__);    \
            assert(0);                                                  \
        }                                                               \
    } while(0);

__attribute__((always_inline)) void *
xmemdup(void *src, size_t size);

__attribute__((always_inline)) void
xmemmove(void *dst, void *src, size_t size);

#endif //L2_OOP_LIB_MEM_H
