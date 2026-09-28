#include "aisort.h"
#include <stdio.h>
#include <stdlib.h>

// === Claude (sonnet 5) written sorting algorithms ===

static void claude_swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// == Bubble sort ==

void claude_bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                claude_swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped) break; /* no swaps means the array is sorted */
    }
}



// == Merge sort ==

static void claude_merge(int arr[], int tmp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
 
    while (i <= mid && j <= right)
        tmp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++]; /* <= keeps it stable */
    while (i <= mid)   tmp[k++] = arr[i++];
    while (j <= right) tmp[k++] = arr[j++];
 
    for (k = left; k <= right; k++)
        arr[k] = tmp[k];
}

static void claude_merge_sort_rec(int arr[], int tmp[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    claude_merge_sort_rec(arr, tmp, left, mid);
    claude_merge_sort_rec(arr, tmp, mid + 1, right);
    claude_merge(arr, tmp, left, mid, right);
}



void claude_merge_sort(int arr[], int n)
{
    if (n < 2) return;
    int *tmp = malloc(n * sizeof *tmp);
    if (!tmp) {
        fprintf(stderr, "merge_sort: out of memory\n");
        return;
    }
    claude_merge_sort_rec(arr, tmp, 0, n - 1);
    free(tmp);

}

// == Quick sort ==

static int claude_partition(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    claude_swap(&arr[mid], &arr[high]); /* move pivot to the end */
    int pivot = arr[high];
 
    int i = low - 1; /* boundary of the "<= pivot" region */
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot)
            claude_swap(&arr[++i], &arr[j]);
    }
    claude_swap(&arr[i + 1], &arr[high]); /* put pivot in its final spot */
    return i + 1;
}


static void claude_quick_sort_rec(int arr[], int low, int high) {
    if (low < high) {
        int p = claude_partition(arr, low, high);
        claude_quick_sort_rec(arr, low, p - 1);
        claude_quick_sort_rec(arr, p + 1, high);
    }
}

void claude_quick_sort(int arr[], int n) {
    if (n > 1) claude_quick_sort_rec(arr, 0, n - 1);
}


