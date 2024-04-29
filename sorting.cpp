#include<iostream>    
using namespace std;    
    void print(int a[], int n) 
    {  
    int i;  
    for(i = 0; i < n; i++)    
    {    
       cout<<a[i]<<" ";     
    }        
    }  
 void bubble(int a[], int n) 
 {  
 int i, j, temp;  
   for(i = 0; i < n; i++)    
    {    
      for(j = i+1; j < n; j++)    
        {    
            if(a[j] < a[i])    
            {    
                temp = a[i];    
                a[i] = a[j];    
                a[j] = temp;     
            }     
        }     
    }     
 }  
 void swap(int arr[],int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(int arr[],int l , int r){
    int pivot = arr[r];
    int i = l-1;
    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr,i,j);
      }  }
    swap(arr,i+1,r);
    return i+1;
}
void quicksort(int arr[],int l , int r){
    if(l<r){
        int pi = partition(arr,l,r);
        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,r);}
    }
void merge(int a[], int beg, int mid, int end){    
    int i, j, k;  
    int n1 = mid - beg + 1;    
    int n2 = end - mid;    
    int LeftArray[n1], RightArray[n2]; 
    for (int i = 0; i < n1; i++)    
    LeftArray[i] = a[beg + i];    
    for (int j = 0; j < n2; j++)    
    RightArray[j] = a[mid + 1 + j];    
    i = 0;   
    j = 0;   
    k = beg;  
      
    while (i < n1 && j < n2){     
        if(LeftArray[i] <= RightArray[j]) {   
            a[k] = LeftArray[i];    
            i++;  }   
        else  {  
            a[k] = RightArray[j];    
            j++;  }  
        k++; }    
    while (i<n1) {   
        a[k] = LeftArray[i];    
        i++;    
        k++;   }    
    while (j<n2) {   
        a[k] = RightArray[j];    
        j++;    
        k++; }   
}    
void mergeSort(int a[], int beg, int end) { 
    if (beg < end){   
        int mid = (beg + end) / 2;  
        mergeSort(a, beg, mid);  
        mergeSort(a, mid + 1, end);  
        merge(a, beg, mid, end);}     
}  
void insert(int a[], int n) 
{  
    int i, j, temp;  
    for (i = 1; i < n; i++) {  
        temp = a[i];  
        j = i - 1;  
  
        while(j>=0 && temp <= a[j]) 
        {    
            a[j+1] = a[j];     
            j = j-1;    
        }    
        a[j+1] = temp; }    }  

        int getMax(int a[], int n) {  
   int max = a[0];  
   for(int i = 1; i<n; i++) {  
      if(a[i] > max)  
         max = a[i];  }  
   return max; 
}    
void countingSort(int a[], int n, int place) { 
  int output[n + 1];  
  int count[10] = {0};      
  for (int i = 0; i < n; i++)  
    count[(a[i] / place) % 10]++;    
  for (int i = 1; i < 10; i++)  
    count[i] += count[i - 1];  
  for (int i = n - 1; i >= 0; i--) {  
    output[count[(a[i] / place) % 10] - 1] = a[i];  
    count[(a[i] / place) % 10]--;  
  }  
  for (int i = 0; i < n; i++)  
    a[i] = output[i];  
}   
void radixsort(int a[], int n) {  
  int max = getMax(a, n);   
  for (int place = 1; max / place > 0; place *= 10)  
    countingSort(a, n, place);  
}  
void heapify(int a[], int n, int i)  
{  
    int largest = i;
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 
    if (left < n && a[left] > a[largest])  
        largest = left;  
    if (right < n && a[right] > a[largest])  
        largest = right;  
    if (largest != i) {  
        int temp = a[i];  
        a[i] = a[largest];  
        a[largest] = temp;  
        heapify(a, n, largest);  
    }  } 
void heapSort(int a[], int n)  
{  
    for (int i = n / 2 - 1; i >= 0; i--)  
        heapify(a, n, i);  
    for (int i = n - 1; i >= 0; i--) {  
        int temp = a[0];  
        a[0] = a[i];  
        a[i] = temp;  
        heapify(a, i, 0);  
  }   }  
 
int main(){
    int i, j,temp;         
    int n ;  
    cout<<"Enter the number of elements to be entered\n" ;
    cin>>n;
    int a[n] ;
     cout<<"Enter the elements\n";
    for(int k=0;k<n;k++){
       
        cin>>a[k];
    } 
    cout<<"Press 1 for bubble sort \n";
    cout<<"Press 2 for radix sort\n";
    cout<<"Press 3 for quick sort \n";
    cout<<"Press 4 for merge sort \n";
    cout<<"Press 5 for  selection sort \n";
    cout<<"Press 6 for  merge sort \n";
    int n1,c;
    cin >> n1;
    if(n1>0 && n1<7){
        switch(n1 ){
            case 1: {
                
                     cout<<"Before sorting array elements are - \n";  
                     print(a, n);  
                      bubble(a, n);  
                      cout<<"\nAfter sorting array elements are - \n";    
                          print(a, n);  
                              break; 
            }
            case 2: {
                cout<<"Before sorting array elements are - \n";  
                          print(a,n);  
                         radixsort(a, n);  
                        cout<<"\n\nAfter applying Radix sort, the array elements are - \n";  
                         print(a, n);  
            } 
            break;
            case 3:{
                   quicksort(a,0,n);

                     print(a,n);
                 }  
                 case 4: {
                    cout<<"Before sorting array elements are - \n";  
                   print(a, n);  
                   mergeSort(a, 0, n - 1);  
                    cout<<"\nAfter sorting array elements are - \n";  
                       print(a, n);  
                 
                 }
                 case 5: {
                    cout<<"Before sorting array elements are - "<<endl;  
                           print(a, n);  
                         insert(a, n);  
                           cout<<"\nAfter sorting array elements are - "<<endl;  
                         print(a, n);  
                 }
                 case 6:{
                    cout<<"Before sorting array elements are - \n";  
                     print(a, n);  
                      heapSort(a, n);  
                        cout<<"\nAfter sorting array elements are - \n";    
                      print(a, n);  
                 }
              } }
    else 
    cout<<"Please press valid options\n";
}
