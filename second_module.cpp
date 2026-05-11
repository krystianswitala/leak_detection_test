#include "common_mem_sanity.hpp"
#include "second_module.hpp"

uint8_t* create_buffer(size_t size)
{
    uint8_t* buffer = new uint8_t[size];
    for (size_t i = 0; i < size; ++i) {
        buffer[i] = static_cast<uint8_t>((size - 1 - i) % 256);
    }
    return buffer;
}

void buffer_operations(uint8_t* buffer, size_t size)
{
    if (buffer == nullptr) {
        return;
    }
    for (size_t i = 0; i < size; ++i) {
        buffer[i] = static_cast<uint8_t>((buffer[i] + 1) % 256);
    }
}