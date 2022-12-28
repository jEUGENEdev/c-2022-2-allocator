#include <stdio.h>
#include "allocator.h"

int main() {
    allocator_t allocator;
    allocator_init(&allocator, sizeof(int*), 3);
    int* i1 = m_alloc(&allocator);
    int* i2 = m_alloc(&allocator);
    int* i3 = m_alloc(&allocator);

    *i1 = 10;
    *i2 = 20;
    *i3 = 30;

    printf("%lld\n", sizeof(void *));
    printf("%lld   %d\n", &i1, *i1);
    printf("%lld   %d\n", &i2, *i2);
    printf("%lld   %d\n", &i3, *i3);
    return 0;
}
