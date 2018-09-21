/* Call Library source file */
 #pragma comment(lib, "nidaqmx.lib")
#include <stdio.h>
#include <NIDAQmx.h>
#include "extcode.h"

extern "C"{_declspec(dllexport) int32_t writeDigital(void);
}
#define DAQmxErrChk(functionCall) if( DAQmxFailed(error=(functionCall)) ) goto Error; else

extern "C"{_declspec(dllexport) int32_t writeDigital(void)
{
	int         error=0;
	TaskHandle	taskHandle=0;
	uInt32      data=0xffffffff;
	char        errBuff[2048]={'\0'};
	int32		written;

	/*********************************************/
	// DAQmx Configure Code
	/*********************************************/
	DAQmxErrChk (DAQmxCreateTask("",&taskHandle));
	DAQmxErrChk (DAQmxCreateDOChan(taskHandle,"Dev1/port0","",DAQmx_Val_ChanForAllLines));

	/*********************************************/
	// DAQmx Start Code
	/*********************************************/
	DAQmxErrChk (DAQmxStartTask(taskHandle));

	/*********************************************/
	// DAQmx Write Code
	/*********************************************/
	DAQmxErrChk (DAQmxWriteDigitalU32(taskHandle,1,1,10.0,DAQmx_Val_GroupByChannel,&data,&written,NULL));

Error:
	if( DAQmxFailed(error) )
		DAQmxGetExtendedErrorInfo(errBuff,2048);
	if( taskHandle!=0 ) {
		/*********************************************/
		// DAQmx Stop Code
		/*********************************************/
		DAQmxStopTask(taskHandle);
		DAQmxClearTask(taskHandle);
	}
//	if( DAQmxFailed(error) )
//		printf("DAQmx Error: %s\n",errBuff);
//	printf("End of program, press Enter key to quit\n");
//	getchar();
	return 0;
}
}