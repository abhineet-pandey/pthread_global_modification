
//////////////////////////////////////////////////
// Program Part           2                     //
// Abhineet Pandey                   on 11/07/17//
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//calling header files
//////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//////////////////////////////////////////////////
//creating global variable and initilizing it to 0
//////////////////////////////////////////////////
int global =0;
//////////////////////////////////////////////////
// function to print the value and modify the 
//global variable 
//////////////////////////////////////////////////
void *printhello(void *vargp)
{
    int thid= (int)vargp;
    int global1=global;
	global+=thid;
    printf("***Hello World*** this is Thread No.=> %d and I recieved Global variable as %d and modified it to %d \n",thid,global1,global);
    pthread_exit(NULL);
}

int main()
{

    int num=10;
    int i;
    void * exit_status;
    pthread_t tid[num];
    printf("\t\t\t\t\t\t*************************\n");
    printf("\t\t\t\t\t\t***** Program part 2*****\n");
    printf("\t\t\t\t\t\t*****Abhineet Pandey*****\n"); 
    printf("\t\t\t\t\t\t*************************\n");
    printf("Initilizing Threads\n");
//////////////////////////////////////////////////
// creating 10 threads to print their value 
// according to the current value 
//////////////////////////////////////////////////
    for(i=0;i<num;i++){
        pthread_create(&tid[i], NULL, printhello,(void *)i);
        printf("In main::: Thread Id for => %d is => %d recieved global variable as %d \n",i,tid[i],global);
    }
//////////////////////////////////////////////////
//waiting for thread termination
//////////////////////////////////////////////////
    for (i=0;i<num;i++){
        printf("waiting for thread => %d to terminate\n",i);
        pthread_join(tid[i], &exit_status);
    }
    printf("After Termination of all Inilitized Threads\n");
    // terminating main
    printf("Main thread terminating\n");
    pthread_exit(NULL);
    exit(0);
}


