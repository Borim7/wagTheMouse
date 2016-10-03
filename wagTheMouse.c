#include <stdio.h>
#include <windows.h>

int main(int argc, char** argv){
	//POINT lastPos;
	
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
	
	// get initial position
	/*int success = GetCursorPos(&lastPos);
	if(!success){
		printf("can not determine mouse position\n");
		exit(-1);
	}*/
	
	while(1){
		// sleep until next check
		Sleep(waitMin * 60000);
		
		EXECUTION_STATE state = SetThreadExecutionState(ES_DISPLAY_REQUIRED);
		
		if(state == 0){
			printf("set state failed\n");
		}else{
			printf("#");
		}
		/*// get current positon
		POINT currentPos;
		success = GetCursorPos(&currentPos);
		if(!success){
			printf("can not determine current mouse position\n");
			exit(-1);
		}
		
		// check with last known position
		if(lastPos.x == currentPos.x && lastPos.y == currentPos.y){
			// mouse not moved -> wag the mouse
			success = SetCursorPos(currentPos.x + 1, currentPos.y);
			if(!success){
				printf("can not set mouse position\n");
				exit(-1);
			
			} else {
				// notify that mouse was moved
				printf("S");
			}
			
		}
		
		// update last known position
		lastPos = currentPos;
		*/
	}
	
	return 0;
}