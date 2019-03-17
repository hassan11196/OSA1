#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

struct proc{
    float burst_time;
    int priority;
};

int main(){
    int num ; // Number of Processes
    float avg_waitt, avg_burstt,avg_turnt; // Avg. Wait time, Avg. Burst time and Avg. Turnaround time, respectively
    int total = 0,pos = 0, temp = 0;
    printf("Enter Number of Processes : ");
    scanf("%d",&num);
    
    float *btimes = (float*)malloc(num*sizeof(int));
    int *wtimes = (int*)malloc(num*sizeof(int));
    int *tatimes = (int*)malloc(num*sizeof(int));
    int *priors = (int*)malloc(num*sizeof(int));
    int *procs = (int*)malloc(num*sizeof(int));
    printf("Enter Burst Time and Priority for respective processes. (Burst time in seconds) \n");
    for(int i = 0; i < num; i++){
        printf("\nBurst time for Process %d : ", i + 1);
        scanf("%f",&btimes[i]);
        printf("Priorty for Process %d : ", i + 1);
        scanf("%d",&priors[i]);
        procs[i] = i + 1;
    }
    for(int i = 0; i < num; i++){
        pos = i;
        for(int j = i; j < num; j++){
            if(btimes[j] < btimes[pos]){
                pos = j;
            }
        }
        temp = btimes[i];
        btimes[i] = btimes[pos];
        btimes[pos] = temp;

        temp = procs[i];
        procs[i] = procs[pos];
        procs[pos] = temp;
    }
    wtimes[0] = 0;
    for(int i = 1; i < num; i++){
        wtimes[i] = 0;
        for(int j = 0; j < i; j++){
            wtimes[i]+=btimes[j];
        }
        total += wtimes[i];
    } 
    avg_waitt = (float)total/num;
    total=0;
    printf("\nProcess\tBurstime\tWaiting Time\tTurnaround Time");
    for(int i = 0; i < num; i++){
        tatimes[i] = btimes[i] +wtimes[i];
        total += tatimes[i];
        printf("\nP%d\t%f\t\t%d\t\t%d",procs[i],btimes[i],wtimes[i],tatimes[i]);
    }
    avg_turnt = (float)total/num;
    printf("\n\nAverage Waiting Time=%f",avg_waitt);
    printf("\nAverage Turnaround Time=%f\n",avg_turnt);

    free(procs);
    free(priors);
    free(tatimes);
    free(wtimes);
    free(btimes);

    return 0;
}
