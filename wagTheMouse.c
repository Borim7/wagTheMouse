#include <stdio.h>
#include <windows.h>

int main(int argc, char** argv){
	int waitMin = 14;
	
	// set wait time if valid number is passed as argument
	if(argc == 2){
		int temp = atoi(argv[1]);
		if(temp > 0){
			waitMin = temp;
			printf("set check interval to %i minutes\n", temp);
		} else {
			printf("parameter is not a number\n");
			exit(-1);
		}
	}
	
	while(1){
		// sleep until next check
		Sleep(waitMin * 60000);
		
		EXECUTION_STATE state = SetThreadExecutionState(ES_DISPLAY_REQUIRED);
		
		if(state == 0){
			printf("set state failed\n");
		}else{
			printf("#");
		}
	}
	
	return 0;
}