///\file function.c

#include "function.h"
int aux=0;
task taskuri[20],taskAux;
///\fn bubbleSort( task arr[], int n)
void bubbleSort( task arr[], int n){

///\param task arr[]
///\param n
///\brief Implements operation: sorting.

    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            /// We start sorting the task by their duration from lowest to highest
            ///
            if (arr[j].duration > arr[j+1].duration)
            {
                taskAux.start = arr[j].start;
                taskAux.finish=arr[j].finish;
                taskAux.duration=arr[j].duration;

                arr[j].start = arr[j+1].start;
                arr[j].finish = arr[j+1].finish;
                arr[j].duration = arr[j+1].duration;

                arr[j+1].start= taskAux.start;
                arr[j+1].finish= taskAux.finish;
                arr[j+1].duration= taskAux.duration;
            }
            ///\brief If the duration of 2 task is equal, we sort them by the starting time
            else if(arr[j].duration == arr[j+1].duration)
            {
                if(arr[j].start > arr[j+1].start)
                {
                    taskAux.start = arr[j].start;
                    taskAux.finish=arr[j].finish;
                    taskAux.duration=arr[j].duration;

                    arr[j].start = arr[j+1].start;
                    arr[j].finish = arr[j+1].finish;
                    arr[j].duration = arr[j+1].duration;

                    arr[j+1].start= taskAux.start;
                    arr[j+1].finish= taskAux.finish;
                    arr[j+1].duration= taskAux.duration;

                }

            }


}


///\fn sortare(task taskuri[],int n)
int sortare( task taskuri[],int n){

///\param taskuri[]
///\param n

    int i;
    int j;
    int k=1;
    int number_of_tasks;
    /// aux we save the finish time of the first task in an variable aux
    aux=taskuri[0].finish;
    for(i=0; i<=n-2; i++)
    {
        for(j=i+1; j<=n-1; j++)
        {
            ///\brief We compare if finish time of the first task is smaller than the start time of the second to see if they overlap
            if(aux<=taskuri[j].start)
            {
                ///\brief Variable k represents the total duration of tasks

                k=k+1;
                ///\brief Variable aux is now the finish time of the new task
                aux=taskuri[j].finish;
                ///\brief If the condition if happens, we also move on to the next task
                i++;
            }
        }

    }

    return k;


}


