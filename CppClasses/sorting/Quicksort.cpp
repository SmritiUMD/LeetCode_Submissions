/******************************************************************************
@author Smriti Gupta
@date created- October 11,2020
*******************************************************************************/


#include<bits/stdc++.h> 

using namespace std;

class QuickSort
{
  
  vector<int>arr;
  
  int n;
  
  void swap(int *x, int *y);\
  
  int partition(vector<int>& arr, int high, int low);
  
  public:
  
  QuickSort(int x);
  void quicksort(vector<int>& arr,int low, int high);
  void printArray(vector<int>& arr, int n);
  
};

QuickSort::QuickSort(int x)
{
    int n=x;
}

void QuickSort::quicksort(vector<int> &arr, int low, int high)
{
    if(low<high)
    {
        //pi_index is the index oof partition
        int p_index=partition(arr, low, high);
        
        quicksort(arr, low, p_index-1);
        
        quicksort(arr, p_index+1, high);
    }
}

void QuickSort::swap(int* x, int* y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
    
}

int QuickSort::partition(vector<int> &arr, int low, int high)
{
    int  pivot=arr[high];
    
    int  j=low-1;
    
    for(int i=low; i<=high-1;i++)
    {
        if(arr[i]<pivot)
        {
            j++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[j+1], &arr[high]);
    
    return (j+1);
}

void QuickSort::printArray(vector<int>& arr, int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
        cout<<endl;
    }
}


int main()
{
    vector<int>arr={64,66,22,11,90,33,67};
    
    int n=arr.size();
    
    QuickSort Q( n);
    Q.quicksort(arr, 0,n-1);
    // called printing method to see output
    Q.printArray(arr, n);
    
    
    return 0;
}

