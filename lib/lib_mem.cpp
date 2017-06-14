#include "vectorina.h"

inline void *
xmemdup(void *src, size_t size)
{
    xassert(src, "error src");
    void *dst = malloc(size);
    xassert(dst, "cannot allocate memory");
    memmove(dst, src, size);
    return dst;
}

inline void
xmemmove(void *dst, void *src, size_t size)
{
    xassert(dst, "error dst");
    xassert(src, "error src");
    memmove(dst, src, size);
}
