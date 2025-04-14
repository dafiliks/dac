#ifndef DAC_H
#define DAC_H

#include <stdlib.h>
#include <assert.h>

typedef struct {
    int* m_data;
    size_t m_size;
    size_t m_capacity;
} Da;

Da* da_init(const size_t capacity)
{
    Da* da = malloc(sizeof(Da));
    da->m_data = malloc(capacity * sizeof(int));
    da->m_size = 0;
    da->m_capacity = capacity;
    return da;
}

Da* da_resize(Da* da, const size_t new_capacity)
{
    int* new_data = malloc(new_capacity * sizeof(int));
    for (size_t i = 0; i < da->m_size; i++)
    {
        new_data[i] = da->m_data[i];
    }
    free(da->m_data);
    da->m_data = new_data;
    da->m_capacity = new_capacity;
    return da;
}

Da* da_pushback(Da* da, int data)
{
    if (da->m_capacity == da->m_size)
    {
        da_resize(da, da->m_capacity * 2);
    }
    da->m_data[da->m_size] = data;
    da->m_size++;
    return da;
}

Da* da_pop(Da *da)
{
    assert(da->m_size > 0);
    da->m_size--;
    da = da_resize(da, da->m_size);
    if (da->m_size * 4 < da->m_capacity)
    {
        da_resize(da, da->m_capacity / 2);
    }
    return da;
}

void da_print(Da* da)
{
    for (size_t i = 0; i < da->m_size; i++)
    {
        printf("%i: %d\n", i, da->m_data[i]);
    }
}

void da_cleanup(Da *da)
{
    free(da->m_data);
    free(da);
}

#endif
