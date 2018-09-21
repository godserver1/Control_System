/* Call Library source file */

#pragma comment(lib, "nidaqmx.lib")
#include <stdio.h>
#include <NIDAQmx.h>
#include "extcode.h"

extern "C"{_declspec(dllexport) int32_t WriteDigChan(uint8_t data[]);
}
#define DAQmxErrChk(functionCall) if( DAQmxFailed(error=(functionCall)) ) goto Error; else

extern "C"{_declspec(dllexport) int32_t WriteDigChan(uint8_t data[])
{
	int i = 0;
	int n = 1000;
	for (int i = 0; i < 1000; i++){
		int32       error = 0;
		TaskHandle  taskHandle = 0;
		//	uInt8       data[8]={1,1,0,1,1,1,1,1};
		char        errBuff[2048] = { '\0' };

		/*********************************************/
		// DAQmx Configure Code
		/*********************************************/
		DAQmxErrChk(DAQmxCreateTask("", &taskHandle));
		DAQmxErrChk(DAQmxCreateDOChan(taskHandle, "Dev1/port0:3", "", DAQmx_Val_ChanForAllLines));

		/*********************************************/
		// DAQmx Start Code
		/*********************************************/
		DAQmxErrChk(DAQmxStartTask(taskHandle));

		/*********************************************/
		// DAQmx Write Code
		/*********************************************/
		DAQmxErrChk(DAQmxWriteDigitalLines(taskHandle, 1, 1, 10.0, DAQmx_Val_GroupByChannel, data, NULL, NULL));

	Error:
		if (DAQmxFailed(error))
			DAQmxGetExtendedErrorInfo(errBuff, 2048);
		if (taskHandle != 0) {
			/*********************************************/
			// DAQmx Stop Code
			/*********************************************/
			DAQmxStopTask(taskHandle);
			DAQmxClearTask(taskHandle);
		}
	}
//	if( DAQmxFailed(error) )
//		printf("DAQmx Error: %s\n",errBuff);
//	printf("End of program, press Enter key to quit\n");
//	getchar();
	return 0;
}
}
