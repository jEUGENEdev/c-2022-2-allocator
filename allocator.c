//
// Created by admin on 25.12.2022.
//

#include "allocator.h"

allocator_t HelloAllocator(size_t max_size) {
    allocator_t allocator;
    allocator.size = max_size;
    allocator.ptr = malloc(max_size);
    return allocator;
}
