
//////////////////////////////////////////////////
// Program Part 1		                            //
// Abhineet Pandey                   on 11/07/17//
//////////////////////////////////////////////////
//////////////////////////////////////////////////
//including header files                        //
//////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
/////////////////////////////////////////////////
// function to print hello world by th threads // 
/////////////////////////////////////////////////
void *printhello(void *vargp)
{
	int thid= (int)vargp;  
  printf("\t***Hello World*** this is Thread No.=> %d \n",thid);
    pthread_exit(NULL);
}
//main function  
int main()
{
/////////////////////////////////////////////////
//initilizing variables
// num for number of threads
// i for initilizing threads count
/////////////////////////////////////////////////

int num=10;
int i;
void * exit_status;
   pthread_t tid[num];
    printf("\t\t\t\t\t\t*************************\n");
    printf("\t\t\t\t\t\t***** Program part 1*****\n");
    printf("\t\t\t\t\t\t*****Abhineet Pandey*****\n"); 
    printf("\t\t\t\t\t\t*************************\n");
    printf("Initilizing Threads\n");
/////////////////////////////////////////////////
//creating 10 threads and calling printhello
// to print the value
/////////////////////////////////////////////////

for(i=0;i<num;i++){
    pthread_create(&tid[i], NULL, printhello,(void *)i);
printf("In main::: Thread Id for => %d is => %d\n",i,tid[i]);
   } 
/////////////////////////////////////////////////
// Waiting for threads to join so to safely
// terminatte main thread
/////////////////////////////////////////////////

for (i=0;i<num;i++){
printf("waiting for thread => %d to terminate\n",i);
pthread_join(tid[i], &exit_status);
}
    printf("After Termination of all Inilitized Threads\n");
/////////////////////////////////////////////////
// Terminating main function
/////////////////////////////////////////////////

printf("Main thread terminatingi\n");
pthread_exit(NULL);
    exit(0);
}

