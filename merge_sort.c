#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void merge (int *arr, int *left, int *right, int l_left, int l_right)
{
  int i = 0;
  int j = 0;
  int k = 0;
  if (l_left && l_right > 0) {
    while (i < l_left && j < l_right) {
      if (left[i] < right[j]) {
        arr[k] = left[i];
        i++;
      }
      else {
        arr[k] = right[j];
        j++;
      }
      k++;
    }

    while (i < l_left) {
      arr[k] = left[i];
      i++;
      k++;
    }

    while (j < l_right) {
      arr[k] = right[j];
      j++;
      k++;
    }
  }
}

void mergesort (int arr[], int arr_size)
{
  int i = 0;
  int j = 0;

  int l_left = floor(arr_size/2);
  int l_right = arr_size - l_left;

  int left[l_left];
  for (i = 0; i < l_left; i++) {
    left[i] = arr[i];
  }

  int right[l_right];
  for (i = l_left; i < arr_size; i++) {
    right[j] = arr[i];
    j++;
  }

  if (l_left && l_right > 0) {
    mergesort(left, l_left);
    mergesort(right, l_right);
  }

  merge(arr, left, right, l_left, l_right);
}

int main(void)
{
  int i;

  int arr[] = {23, 43, -2, 45, 100, 572, 563, 275, 238, 678, 335, 654, 123};
  /* int arr[] = {1, 5, 3, 0}; */

  int arr_size = sizeof(arr) / sizeof(arr[0]);
  mergesort(arr, arr_size);
  for (i = 0; i < arr_size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
