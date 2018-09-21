/* Call Library source file */

#include "extcode.h"

extern "C"{_declspec(dllexport) void numAddition(int32_t arg1, int32_t arg2, int32_t *arg3);
}
extern "C"{_declspec(dllexport) void numAddition(int32_t arg1, int32_t arg2, int32_t *arg3)
{

	*arg3 = arg1 + arg2;

}}

