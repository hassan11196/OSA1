#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

int main()
{

    int p_pipe[2];
    int c_pipe[2];
    char buff[50];

    if (pipe(p_pipe) || pipe(c_pipe)){
        perror("pipe error");
        exit(1);
    }

    pid_t pid = fork();

    if (pid == -1){
        perror("fork()");
        exit(1);
    }

    if (pid == 0){
        char child[] = "Child Writes. Parent Reads\n";
        int in, out;
        in = c_pipe[0];

        // in = p_pipe[0];  

        out = p_pipe[1];

        for (int i = 0; i < 10; ++i){
            read(in, buff, 50);
            printf("Parent: %s", buff);
            write(out, child, strlen(child) + 1);
        }
    }

    else{
        char parent[] = "Parent Writes. Child Reads\n";

        int in, out;
        in = p_pipe[0];
        out = c_pipe[1];

        // out = parent_pipe[1];  

        for (int i = 0; i < 10; ++i){
            write(out, parent, strlen(parent) + 1);
            read(in, buff, 50);
            printf("Child: %s", buff);
        }
    }
}
