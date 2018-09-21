/* Call Library source file */
#pragma comment(lib, "nidaqmx.lib")
#include "extcode.h"
#include <iostream>
#include <map>
using namespace std;

extern "C"{_declspec(dllexport) void generateHmap(char InstName[], int32_t Location[]);
}
extern "C"{_declspec(dllexport) void generateHmap(char InstName[], int32_t Location[])
{

	

}
}
