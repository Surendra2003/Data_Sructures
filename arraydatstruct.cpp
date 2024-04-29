// array data structure operations by the switch caseprogramme

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




























































// array data structtures linear search.


/* 
#include<iostream>
using namespace std;
int search( int array[],int n,int x)
{
    for(int i=0;i<n;i++)
    if (array[i]==x)
    return i;
    else 
    return -1;

}
int main()
{
    int array[]={2,4,0,1,9};
    int x=1;
    int n=sizeof(array)/sizeof(array[0]);
    int result=search(array,n,x);
    (result==-1);
    cout<<"Element not found"<<endl;
    cout<<"element found at index : "<<result;
}

*/


/*

//program to store the elements in array by using the data structure

#include <iostream>
using namespace std;
 int main() 
 {
   int arr[] = {1,3,5,7,8};
   int item = 10, k = 3, n = 5;
   int i = 0, j = n;   
   cout<<"The original array elements are : \n";
  // printf("The original array elements are :\n");
   for(i = 0; i<n; i++)
    {
     // printf("arr[%d] = %d \n", i, arr[i]);
      cout<< "arr=i \n"3W << i <<arr[i];
   }
}

*/





/*
//To insert one or more data elements into an array

#include <stdio.h>

main() {
   int LA[] = {1,3,5,7,8};
   int item = 10, k = 3, n = 5;
   int i = 0, j = n;
   
   printf("The original array elements are :\n");

   for(i = 0; i<n; i++)
      {
      printf("LA[%d] = %d \n", i, LA[i]);

      }
       n = n + 1;
	
     while( j >= k)
      {
      LA[j+1] = LA[j];
      j = j - 1;
      }
      
       LA[k] = item;

   printf("The array elements after insertion :\n");

   for(i = 0; i<n; i++) {
      printf("LA[%d] = %d \n", i, LA[i]);
   }
}
*/



/*

// to removing an existing element from the array .

#include <stdio.h>

void main();
 {
   int LA[] = {1,3,5,7,8};
   int k = 3, n = 5;
   int i, j;
   
   printf("The original array elements are :\n");
	
   for(i = 0; i<n; i++) {
      printf("LA[%d] = %d \n", i, LA[i]);
   }
    
   j = k;
while( j < n) {
      LA[j-1] = LA[j];
      j = j + 1;
   }

   n = n -1;
   
   printf("The array elements after deletion :\n");
	
   for(i = 0; i<n; i++) {
      printf("LA[%d] = %d \n", i, LA[i]);
   }
}

*/




/*
//linear search algorithm

#include <iostream>
using namespace std;

int search(int array[], int n, int x) {

  // Going through array sequencially
  for (int i = 0; i < n; i++)
    if (array[i] == x)
      return i;
  return -1;
  }

int main() {
  int array[] = {2, 4, 0, 1, 9};
  int x = 1;
  int n = sizeof(array) / sizeof(array[0]);

  int result = search(array, n, x);

  (result == -1) ? cout << "Element not found" : cout << "Element found at index: " << result;
}

*/



/*

// Binary search


#include <iostream>  
#include <conio.h>  
using namespace std;  
int main ()  
{  
    // declaration of the variables and array  
    int arr[100], st, mid, end, i, num, tgt;  
      
    cout << " Define the size of the array: " << endl;  
    cin >> num; // get size  
      
    // enter only sorted array  
        cout << " Enter the values in sorted array either ascending or descending order: " << endl;  
    // use for loop to iterate values  
    for (i = 0; i < num; i++)  
    {  
        cout << " arr [" << i << "] = ";  
        cin >> arr[i];  
    }  
      
    // initialize the starting and ending variable's values  
    st = 0;  
    end = num - 1; // size of array (num) - 1  
      
    // define the item or value to be search  
    cout << " Define a value to be searched from sorted array: " << endl;  
    cin >> tgt;  
      
    // use while loop to check 'st', should be less than equal to 'end'.  
    while ( st <= end)  
    {  
        // get middle value by splitting into half  
        mid = ( st + end ) / 2;  
         if we get the target value at mid index, 
        print the position and exit from the program.   
        if (arr[mid] == tgt)  
        {  
            cout << " Element is found at index " << (mid + 1);  
            exit (0); // use for exit program the program  
        }  
        // check the value of target element is greater than the mid element' value  
        else if ( tgt > arr[mid])  
        {  
            st = mid + 1; // set the new value for st variable  
        }  
          
        // check the value of target element is less than the mid element' value  
        else if ( tgt < arr[mid])  
        {  
            end = mid - 1; // set the new value for end variable  
        }  
    }  
    cout << " Number is not found. " << endl;  
    return 0;  
}   

*/





























































/* 
******************ARRAY DATA STRUCTURE************
implement the operations on array data structure.
transversal in array .
insertion in array. 
deletion in array.
linear searching in array.
Binary searching in array.
sorting in array.
merging in array.
*/
// In an unsorted array, 
// the search operation can be performed by 
// linear traversal from the first element to the last element. 

// C++ program to implement linear

/*


// search in unsorted array
#include <bits/stdc++.h>
using namespace std;

// Function to implement search operation

int findElement(int arr[], int n, int key)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == key)
			return i;
	
	// If the key is not found
	return -1;
}

// Driver's Code
int main()
{
	int arr[] = { 12, 34, 10, 6, 40 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Using a last element as search element
	int key = 40;

	// Function call
	int position = findElement(arr, n, key);

	if (position == -1)
		cout << "Element not found";
	else
		cout << "Element Found at Position: "
			<< position + 1;

	return 0;
}

*/



