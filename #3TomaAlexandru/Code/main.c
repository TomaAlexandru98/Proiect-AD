///\file main.c
#include "function.h"

int total_duration=1;
int i;
int j;
int number_of_tasks;
int p;
task taskuri[20];
int main()
{

    /// In functionmain we call all the function declared befored bubblesort(), sortare() from function.h
    int numberArray[1000];
    int n;

    int  total_number_of_tasks;
    FILE *myFile;
    ///\brief We open the file
    myFile = fopen("in.txt", "r");

    ///\brief We check if it is something written in file, if it's now, we return NULL
    if (myFile == NULL)
    {
        printf("Error Reading File\n");
        exit (0);
    }

    fscanf(myFile, "%d,", &numberArray[0]);
    n=numberArray[0];
    j=0;
    ///\brief We check if the position of a number in file is odd or even.

    for (i = 1; i <= n*2; i++)
    {
        fscanf(myFile, "%d,", &numberArray[i] );
        ///\brief If it is odd it represents the start time of a task.
        if(i%2!=0)
        {
            taskuri[j].start=numberArray[i];
        }
        ///\brief If it is even it represents the end time of a task.
        if(i%2==0)
        {
            taskuri[j].finish=numberArray[i];
            j++;
        }
    }
    ///\brief We calculate the duration of each task by substracting the finish time from the start time.
    for (i = 0; i < n; i++)
    {
        taskuri[i].duration=taskuri[i].finish-taskuri[i].start;
    }

    ///\fn bubbleSort  -we call the function bubblesort() which sorts all the task by their duration and start time
    bubbleSort(taskuri,n);


    for (i = 0; i < n; i++)
    {
        printf("task_%d: start_%d, finish_%d , duration_%d\n\n", i,taskuri[i].start,taskuri[i].finish,taskuri[i].duration );
    }
    ///\fn sortare - we call the function sortare() to find out the total maximum duration of non-overlapping tasks.

    total_number_of_tasks=sortare(taskuri,n);
    ///\brief We print the maximum

   printf("Number of maximum tasks is=%d",total_number_of_tasks);
    fclose(myFile);

    return 0;
}
