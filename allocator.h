//
// Created by admin on 25.12.2022.
//

#ifndef C_2022_2_ALLOCATOR_ALLOCATOR_H
#define C_2022_2_ALLOCATOR_ALLOCATOR_H

#include <stdlib.h>
#include "./core/functions.h"

typedef struct {
    void* ptr;
    size_t size;
} allocator_t;

allocator_t HelloAllocator(size_t max_size);

#endif //C_2022_2_ALLOCATOR_ALLOCATOR_H
