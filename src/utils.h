#include <stdbool.h>

#ifndef UTILS_H
#define UTILS_H

#define MAX 3000
#define RUNS 5


typedef void(int_fn)(int);

void *check_memory(void *memory);

/*@brief Measures the exection time of a given function
@param func Any function*/
void exec_time(int_fn func, int_fn fill);

/*@brief Verifies if an array has been correctly sorted
@param arr Any integer array*/
bool verify_result(int arr[]);

/*@Fills an array with numbers in random order
@param arr Any empty integer array*/
int fill_array_rand(int arr[]);

/*@brief Fills an array in reverse order
@param arr Any empty integer array*/
int fill_array_rev(int arr[]);

void test_random(int_fn func);

void test_reverse(int_fn func);
#endif