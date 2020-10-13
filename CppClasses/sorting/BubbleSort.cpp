/******************************************************************************
@author Smriti Gupta
@date created- October 11,2020
*******************************************************************************/

#include<bits/stdc++.h> 

using namespace std;

class BubbleSort
{
  
  vector<int>arr;
  
  int n;
  
//private member function for swapping two numbers
  void swap(int *x, int *y);
  
  public:
  
//constructor
  BubbleSort(int x);
 
	
  //member function for sorting an array
  void bubbleSort(vector<int>& arr,int n);
  
  //member function to print sorted array
  void printArray(vector<int>& arr, int n);
  
    
};

BubbleSort::BubbleSort(int x){
    int n=x;
}



void BubbleSort::swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

void BubbleSort::bubbleSort(vector<int> &arr,int n)
{
  for(int i=0;i<n-1;i++)
  {
      for(int j=0;j<n-i-1;j++)
      {
        if(arr[j]>arr[j+1]) 
            swap(&arr[j],&arr[j+1]);
      }
  }
    
}

void BubbleSort::printArray(vector<int> &arr, int n )
{
    for(int i=0;i<n;i++)
    {
       cout<<arr[i]<<" "; 
    }
}


int main()
{
    vector<int>arr={64,66,22,11,90,33,67};
    
    int n=arr.size();
    
    BubbleSort B( n);
    B.bubbleSort(arr, n);
    // called printing method to see output
    B.printArray(arr, n);
    
    
    return 0;
}

