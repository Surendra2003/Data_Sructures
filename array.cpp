#include <stdio.h>
// Function to implement search operation
int LinearSearch(int arr[], int n, int key)
{     int i;
	for (i = 0; i < n; i++)
	{    if (arr[i] == key)
		    return i;   }
	// If the key is not found
	return -1;   }
int binarySearch(int arr[], int l, int r, int x)
{     if (r >= l) {
        int mid = l + (r - l) / 2;
 // If the element is present at the middle itself
        if (arr[mid] == x)
            return mid;
// If element is smaller than mid, then it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 // Else the element can only be present in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
// We reach here when element is not present in array
    return -1;
}
//function for swapping
void swap(int *xp, int *yp)
{  int temp = *xp;  *xp = *yp; *yp = temp;  }
//function for sorting the array
void selectionSort(int arr[], int n)
{  int i, j, min_idx;
 // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {  // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 // Swap the found minimum element with the first element
           if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }  }
void printArray(int arr[], int size)
{   int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{   int arr[] = { 12, 34, 10, 6, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);
        // Using a last element as search element
	int key = 40;
         // Function call
        int search_algo;
    printf("Choose 1 for Linear search \nChoose 2 for Binary Search\nChoose 3 for using Selection Sort.");
    scanf("%d",&search_algo);
    int position;
    switch(search_algo) {
        case 1:   position = LinearSearch(arr, n, key);
                 if (position == -1)
		printf("Element not found");
	    else 
               printf("Element Found at Position: %d", position + 1);   break;
       case 2:  position = binarySearch(arr, 0, n - 1, key);
        (position == -1) ? printf("Element is not present in array") : printf("Element is present at index %d", position);
        break;
        case 3: selectionSort(arr, n);
        printf("Sorted array: \n");   printArray(arr, n); break;
       default : printf("Please enter either 1 ,2 or 3.");
    }
return 0;
}




































/*
// traversing

#include <stdio.h>
void main()
{
int array[] = {1,2,3,4,5};
int i, n = 5;
printf(" The array elements are: \n " );
for( i=0;i < n; i++)
{
printf(" array[%d] = %d \n " , i, array[i] );
}
}

//  searching
#include<stdio.h>
int findElement(int arr[], int n,  int key)
{
int i;
for (i = 0; i < n; i++)
if (arr[i] == key
return i;
return -1;
}
int main()
{
int arr[] = {1, 4, 0, 6, 3};
int n = sizeof(arr) / sizeof(arr[0]);
int key = 4;
int position = findElement(arr, n, key);
if (position == - 1)
printf("Element not found");
else
printf("Element Found at Position: %d", position + 1 );
return 0;
}

//insertion

#include<stdio.h>
int insertSorted(int arr[], int n,  int key, int capacity)
{
if (n >= capacity)
return n;
arr[n] = key;
return (n + 1);
}
int main()
{
int arr[20] = {8, 5, 6, 9, 0, 7} ;
int capacity = sizeof(arr) / sizeof(arr[0]);
int n = 6;
int i, key = 2;
printf("\n Before Insertion: ");
for (i = 0; i < n; i++)
printf("%d  ", arr[i]);
n = insertSorted(arr, n, key, capacity);
printf("\n After Insertion: ");
for (i = 0; i < n; i++)
printf("%d  ",arr[i]);
return 0;
}

// deletion 

#include<stdio.h>
int findElement(int arr[], int n, int key);
int deleteElement(int arr[], int n, int key)
{
int pos = findElement(arr, n, key);
if (pos == - 1)
{
printf("Element not found");
return n;}
int i;
for (i = pos; i < n - 1; i++)
arr[i] = arr[i + 1];
return n - 1;
}
int findElement(int arr[], int n, int key)
{
int i;
for (i = 0; i < n; i++)
if (arr[i] == key)
return i;return - 1;
}
int main()
{
int i;
int arr[] = {1, 5, 3, 4, 2};
int n = sizeof(arr) / sizeof(arr[0]);
int key = 3;
printf("Array before deletion\n");
for (i = 0; i < n; i++)
printf("%d  ", arr[i]);
n = deleteElement(arr, n, key);
printf("\nArray after deletion\n");
for (i = 0; i < n; i++)
printf("%d  ", arr[i]);
return 0;
}

//  sorting 

#include <stdio.h>
void main()
{
int i, j, a, n, number[30];
printf("Enter the value of N \n");
scanf("%d", &n);
printf("Enter the numbers \n");
for (i = 0; i < n; ++i)
scanf("%d", &number[i]);
for (i = 0; i < n; ++i)
{
for (j = i + 1; j < n; ++j)
{
if (number[i] > number[j])
{
a =  number[i];
number[i] = number[j];
number[j] = a;
}
}
}
printf("The numbers arranged in ascending order are given below \n");
for (i = 0; i < n; ++i)
printf("%d\n", number[i]);
}








1
// Program to implement various operations on arrays (insert, delete, traverse,
copy and merge).
#include<stdio.h>
#incl
2
break;
case 6:
exit(1);
break;
default:
printf("nWrong choice");
getch();
}
}
}
void insert(){
/* This function gets the...

*/
