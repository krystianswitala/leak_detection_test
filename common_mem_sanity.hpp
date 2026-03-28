// Only applied for MSVC in Debug mode, to enable memory leak detection with file and line information.
#if defined(_MSC_VER) && defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdlib>

#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
#endif // _MSC_VER && _DEBUG
