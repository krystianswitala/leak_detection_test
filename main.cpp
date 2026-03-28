#include "common_mem_sanity.hpp"

#include <cstdint>
#include <iostream>
#include <memory>

#include "second_module.hpp"

uint8_t* global_ptr = nullptr;

int main(int, char**)
{
#if defined(_MSC_VER) && defined(_DEBUG)
    // Enable run-time memory leak check for debug builds.
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
#endif // _MSC_VER && _DEBUG

    std::cout << "Hello, from leak_detection_test!\n";

    global_ptr = new uint8_t[1024];
    for (size_t i = 0; i < 1024; ++i) {
        global_ptr[i] = static_cast<uint8_t>(i % 256);
    }

    uint8_t* local_ptr = new uint8_t[512];
    for (size_t i = 0; i < 512; ++i) {
        local_ptr[i] = static_cast<uint8_t>(i % 256);
    }

    uint8_t* another_local_ptr = static_cast<uint8_t*>(malloc(256));
    for (size_t i = 0; i < 256; ++i) {
        another_local_ptr[i] = static_cast<uint8_t>(i % 256);
    }

    uint8_t* buffer_from_module = create_buffer(128);
    uint8_t* buffer_from_module2 = create_buffer(64);

    auto unique_buffer = std::make_unique<uint8_t[]>(256);
    for (size_t i = 0; i < 256; ++i) {
        unique_buffer[i] = static_cast<uint8_t>((i + 10) % 256);
    }
    uint8_t* raw_ptr_from_unique = unique_buffer.release();

    return 0;
}
