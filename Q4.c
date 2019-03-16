#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	pid_t pid1 = fork();
	
	if(pid1 > 0){
		printf("\n Process A \n");
		// Process A
		wait();
		printf("\n Process A - Wait Completed \n");
	}
	else if(pid1 == 0){
		// Process B
		printf("\n Process B \n");		
		pid_t pid2 = fork();
		if(pid2 > 0){
			// Process B - Continued
		}
		else if (pid2 == 0){
			// Process E
			
			pid_t pid3 = fork();
			if(pid3 > 0){
				// Process E - Parent for system call
				
			}
			else if(pid3 == 0){
				// Process E - Child
				printf("\n Process E \n");
				system("ifconfig -a | grep -i \"HWaddr\"");
				return 0;
			}			
				
			//execl("/bin/bash","sh","ifconfig -a | grep -i \"HWaddr\"",NULL);
		}
	}	


	return 0;

}
