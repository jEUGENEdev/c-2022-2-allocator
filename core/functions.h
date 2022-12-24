//
// Created by admin on 25.12.2022.
//

#ifndef C_2022_2_ALLOCATOR_FUNCTIONS_H
#define C_2022_2_ALLOCATOR_FUNCTIONS_H

#include <stdlib.h>

void* m_alloc(size_t size);
void* m_calloc(size_t size);
void* m_realloc(void* memory, size_t new_size);
void m_free(void* memory);

#endif //C_2022_2_ALLOCATOR_FUNCTIONS_H
