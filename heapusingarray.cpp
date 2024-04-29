#include <stdio.h>
// swap function
void swap(int *a, int *b)
{  int temp = *b;  *b = *a; *a = temp;  }
// Function to print the Heap as array
void printArray(char message[], int arr[], int n)
{  printf("%s ",message);
for (int i = 0; i < n; ++i){ 
printf("%d ", arr[i]); }
printf("\n");
}
void heapify(int arr[], int n, int i)
{ int largest = i; // Initialize largest as root
int leftChild = 2 * i + 1; // left child = 2*i + 1
int rightChild = 2 * i + 2; // right child = 2*i + 2
// If left child is greater than root
if (leftChild < n && arr[leftChild] > arr[largest])
largest = leftChild;
// If right child is greater than new largest
if (rightChild < n && arr[rightChild] > arr[largest])
largest = rightChild;
// If largest is not the root
if (largest != i)
{// swap root with the new largest
swap(&arr[i], &arr[largest]);
heapify(arr, n, largest); }  }
// Function to build a Max-Heap from a given array
void buildHeap(int arr[], int n)
{  // Index of last non-leaf node
int lastNonLeafNode = (n / 2) - 1;
// Perform level order traversal in reverse from last non-leaf node to the root node and heapify each node
for (int i = lastNonLeafNode; i >= 0; i--)
{  heapify(arr, n, i); }   }
// Driver Code
void main() {
// Array
int arr[10];
printf("Enter 10 values in the array");
for(int i=0;i<10;i++){
    scanf("%d",&arr[i]);
}
// Size of array
int n = 10; int choice;
printf("\nEnter your Choice\n");
printf("\n1. Print the Array.\n");
printf("\n2. Build and print the Heap.\n");
scanf("%d",&choice);
switch(choice){
    case 1: printArray("Array is : ", arr, n); break;
case 2: buildHeap(arr, n);
    printArray("Array representation of Heap is : ", arr, n); break;
default: printf("Enter 1 or 2 in choice.");
}
}
