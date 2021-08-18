/*
 ============================================================================
 Name        : Task.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Binary Search
 ============================================================================
 */


#include <stdio.h>



int arraySortedOrNot(int arr[], int n)
{

    if (n == 1 || n == 0)
        return 1;


    if (arr[n - 1] < arr[n - 2])
        return 0;


    return arraySortedOrNot(arr, n - 1);
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void selectionSort(int arr[], int n)
{
    int i, j, min_idx;


    for (i = 0; i < n - 1; i++) {

        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}


int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;


		if (arr[mid] == x)
			return mid;


		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);


		return binarySearch(arr, mid + 1, r, x);
	}

	return -1;
}

int main(void)
{
	int arr[] = {100, 12, 2, 55, 3, 4, 10, 40, 6 , 19};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 10;
	if (!(arraySortedOrNot(arr, n)))
	{
		selectionSort(arr,n);
	}


	int result = binarySearch(arr, 0, n - 1, x);
	if(result == -1)
		printf("Not Found");
	else
		printf("Element is present at index %d",result);
	return 0;
}
