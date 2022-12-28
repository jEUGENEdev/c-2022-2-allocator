//
// Created by admin on 25.12.2022.
//

#ifndef C_2022_2_ALLOCATOR_ALLOCATOR_H
#define C_2022_2_ALLOCATOR_ALLOCATOR_H

#include <stdlib.h>

typedef struct {
    void* ptr;
    void* ptr_current;
    size_t block_size;
    size_t number_blocks;
} allocator_t;

void allocator_init(allocator_t* allocator, size_t block_size, size_t number_blocks);

void* m_alloc(allocator_t* allocator);
void* m_calloc(allocator_t* allocator);
void* m_realloc(allocator_t* allocator, size_t size);
void m_free(allocator_t* allocator, void* memory);

#endif //C_2022_2_ALLOCATOR_ALLOCATOR_H
