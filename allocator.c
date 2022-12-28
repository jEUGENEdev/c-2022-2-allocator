//
// Created by admin on 25.12.2022.
//

#include "allocator.h"
#include <stdio.h>

void allocator_init(allocator_t* allocator, size_t block_size, size_t number_blocks) {
    allocator->block_size = block_size;
    allocator->number_blocks = number_blocks;
    allocator->ptr = malloc(sizeof(char) * block_size * number_blocks);
    allocator->ptr_current = allocator->ptr;

    for(size_t i = 0; i < number_blocks - 1; i++) {
        *(void**) (allocator->ptr + i * block_size) = allocator->ptr + (i + 1) * block_size;
    }
    *(void**) ((char*) allocator->ptr + (number_blocks - 1) * block_size) = NULL;
}

void* m_alloc(allocator_t* allocator) {
    void* mem = allocator->ptr_current;
    allocator->ptr_current = *(void**) allocator->ptr_current;
    return mem;
}

void* m_realloc(allocator_t* allocator, size_t size) {
    if(size > allocator->block_size) return NULL;
    return m_alloc(allocator);
}

void* m_calloc(allocator_t* allocator) {
    void* mem = m_alloc(allocator);
    if(*(void**) ((char*) mem) == NULL) return NULL;
    for(size_t i = 0; i < allocator->block_size; i++) {
        *(char*) (mem) = 0;
    }
    return mem;
}

void m_free(allocator_t* allocator, void* memory) {
    *(void**) (memory) = *(void**) (allocator->ptr_current);
    allocator->ptr_current = memory;
}

void deallocate(allocator_t* allocator) {
    free(allocator->ptr);
    free(allocator->ptr_current);
    free(allocator);
}