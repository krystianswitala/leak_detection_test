#include <iostream>
#include <cstdint>
#include <crtdbg.h>

uint8_t *global_ptr = nullptr;

int main(int, char**) {
#if defined(_DEBUG)
    // Enable run-time memory leak check for debug builds.
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif // _DEBUG

    std::cout << "Hello, from leak_detection_test!\n";

    global_ptr = new uint8_t[1024];
    for (size_t i = 0; i < 1024; ++i) {
        global_ptr[i] = static_cast<uint8_t>(i % 256);
    }

    return 0;
}
