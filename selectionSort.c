#include<stdio.h>

void selectionSort ( int arr[],int n)
{
    int i,j,small,temp;
    for(i = 0; i<n-1;i++)
    {
        small = i;
        for (j= i+1;j<n;j++){
            if(arr[j]<arr[small]){
                small = j;
            }}
            temp = arr[small];
            arr[small] = arr[i];
            arr[i] = temp;

    }

}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Perform selection sort
    selectionSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
