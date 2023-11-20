#include<stdio.h>
int binerySearch( int arr[],int size, int target)
{

int left =0;
int right = size-1;
while (left<=right){
    int mid = left +(right -left) /2;
    if(arr[mid]== target){
        return mid;
    }else if (arr[mid]< target){
        left = mid+1;
    }else {
         right = mid -1;
    }
}
   return -1;
}
int main ()
{
    int arr[] = {5,10,15,20,25,30,35,40};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 25;
    int result = binerySearch(arr, size, target);
    if(result != -1)
    {
        printf(" found index no : %d\n", result);
    }else
    {
        printf("not found\n");
    }
     return 0;
}
