#include "utils.h"
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>


void exec_time(int_fn func, int_fn fill)
{   
    int arr = malloc(MAX * sizeof(int));
    fill(arr);
    int n = MAX;

    clock_t start, end;
    double time;

    start = clock();
    func(arr);
    end = clock();

    free(arr);
    time = ((double)(end - start) / CLOCKS_PER_SEC);
    printf("Execution time: %f\n", time);

}

bool verify_result(int arr[])
{
    int ref[] = malloc(MAX * sizeof(int));
    int cnt = 0;
    for(int i = 0; i < MAX; i++)
    {
        ref[i] = i;
    }
    //Very simple correctness check
    for(int i = 0; i < MAX; i++)
    {
        if(arr[i] == ref[i])
        {
            cnt++;
        }
    }
    free(ref);
    if(cnt == MAX) return true;
    else return false;
        
}

void *check_memory(void *memory)
{
    if(!memory)
    {
        fprintf(stderr,"Failed to allocate memory!\n");
        exit(1);
    }
}

int fill_array_rand(int arr[])
{   
    
    for(int i = 0; i < MAX; i++)
    {
        int n = rand() % (MAX + 1);
        arr[i] = n;
    }

    return arr;
}

int fill_array_rev(int arr[])
{
    for(int i = MAX - 1; i >= 0; i--)
    {
        arr[i] = i;
    }

    return arr;
}

void test_random(int_fn func)
{
    int arr[] = malloc(MAX * sizeof(int));
    check_memory(arr);
    fill_array_rand(arr);

    func(arr);
    if(verify_result(arr)) printf("Array correctly sorted\n");
    else printf("Array sorted incorrectly\n");

    free(arr);
    
}

void test_reverse(int_fn func)
{
    int arr[] = malloc(MAX * sizeof(int));
    check_memory(arr);
    fill_array_rev(arr);

    func(arr);
    if(verify_result(arr)) printf("Array correctly sorted\n");
    else printf("Array sorted incorrectly\n");

    free(arr);
}