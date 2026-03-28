#if defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdlib>

#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
#endif // _DEBUG
