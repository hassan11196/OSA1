#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

// Flow of Program is { E B F C D A } To Ensure All children run with no orphans or zombies

int main(){


	pid_t pid[5] = {-1};
	pid[0] = fork();
	wait(NULL); // A waits for child B to die
	if(pid[0] > 0){
				
		pid[2] = fork();
		wait(NULL); // A waits for Child C to die
		if(pid[2] > 0 ){

			pid[3] = fork();
			wait(NULL); // A waits for Child D to die
			if(pid[3] > 0){
				// Process A
				printf("\n\tProcess A - pid : %d - ppid : %d\n",getpid(),getppid());
				system("date");
				return 0;
			}
			else if(pid[3] == 0){
				// Process D
				printf("\n\tProcess D - pid : %d - ppid : %d\n",getpid(),getppid());
				system("date");
				execl("/bin/bash","sh","shell_name_inp.sh",NULL);
				return 0;
			}

			
		}
		else if(pid[2] == 0){
			
			pid[4] = fork();
			wait(NULL); // C waits for child F to die

			if(pid[4] > 0){
				// Process C
				printf("\n\tProcess C goes to sleep\n");
				sleep(5); // C goes to sleep for 5 seconds
				printf("\n\tProcess C - pid : %d - ppid : %d\n",getpid(),getppid());
				system("date");
				return 0;
			}
			else if(pid[4] == 0){
				// Process F
				printf("\n\tProcess F - pid : %d - ppid : %d\n",getpid(),getppid());
				system("date");
				char buf[100], buf2[100], buf3[100];
				sprintf(buf,"ps -p %d -oppid",(getppid()));
				
				// Alternative way of obtaining grand parent pid
				// sprintf(buf3,"pid=%d; (ps -o ppid= -p $(ps -o ppid= -p $pid));",getpid());
				printf("\nPID of Grandparent of F (i.e PID of A) : \n");
				system(buf);
				// system(buf3);
				return 0;
			}
			return 0;
		}
	}
	else if(pid[0] == 0){		
		pid[1] = fork();
		wait(NULL); // B waits for child E to die
		if(pid[1] > 0){
			// Process B
			char num1[10],num2[10];
			printf("\n\tProcess B - pid : %d - ppid : %d",getpid(),getppid());
			system("date");
			printf("\nEnter Two Numbers : ");
			scanf("%s %s",&num1[0],&num2[0]);
			printf("\nPassing %c and %c as arguments to Shell Scipt.\n",num1[0],num2[0]);
			execl("/bin/bash","sh","shell_calc.sh",&num1[0],&num2[0],(void*)0);
			return 0;
		}
		else if (pid[1] == 0){
			// Process E
			printf("\n\tProcess E - pid : %d - ppid : %d",getpid(),getppid());
			system("date");
			printf("\nMac Address : \n");
			//system("ifconfig -a | grep -i \"HWaddr\"");
			execl("/bin/bash","/bin/bash","-c","ifconfig -a | grep -i \"HWaddr\"",(void*)0);
			return 0;
		}
		return 0;
	}	
	return 0;

}


// execv and execl do exactly the same thing, 
// with the difference that execl is intended for use
//  when you know in advance the number of command-line arguments while
//  execv allows the number of arguments to be dynamically determined.

// Before executing a script using exec family ensure that there is a newline \n in last printf