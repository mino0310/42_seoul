#include <stdio.h>

void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    int temp;
    do 
    {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        printf("check\n");
    } while (i <= j);
    // recursion
    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

int main(void)
{
    int arr[10] = {1, 4, 6, 8, 2, 5, 7, 9, 0};
    quickSort(arr, 0, 8);
    
    for (int i = 0; i < 9; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}