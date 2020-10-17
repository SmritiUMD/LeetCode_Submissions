/******************************************************************************
@author Smriti Gupta
@date created- October 11,2020

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

//class for merge sort

class MergeSort
{

 vector<int>num;
 
 int left;
 
 int right;
 
 //private function to merge two arrays
 
 void merge(vector<int>& num, int start, int mid, int end);
  
  public:
  
  //constructor for merge class
  MergeSort(int x, int y);
  
  
  //function for sorting
  void mergeSort(vector<int>& num, int left, int right );
  
  //function for printing array
  void printArray(vector<int>& nums);

};

MergeSort::MergeSort(int l, int r)
{
    int left=l;
    int right=r;
}



 void MergeSort::merge(vector<int>& temp, int start, int mid, int end)
{
    
  int n1 = mid - start + 1;
  int n2 = end - mid;
  
  //creating two temp arrays for left side and right side
  vector < int >left (n1, 0);
  vector < int >right (n2, 0);

    //populate temp the arrays from given array
  for (int i = 0; i < n1; i++)
    {
      left[i] = temp[start + i];
    }
  for (int j = 0; j < n2; j++)
    {
      right[j] = temp[mid + 1 + j];
    }
    //index for left array
  int i = 0;
  
  //index for right array
  int j = 0;
  
  //index for temp array
  int k = start;
 
 //sorting
  while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
    	{
    	  temp[k] = left[i];
    	  i++;
    	}
      else
    	{
    	  temp[k] = right[j];
    	  j++;
    	}
      k++;
    }
    
    //adding the leftover elements if any
  while (i < n1)
    {
      temp[k] = left[i];
      i++;
      k++;
    }
  while (j < n2)
    {
      temp[k] = right[j];
      j++;
      k++;
    }

}

void MergeSort::mergeSort(vector<int>& num, int left, int right)
{
  if (left < right)
    {
        //divide the array in two parts
      int mid = left + (right - left) / 2;
    // run the function recursively for left side and right side
      mergeSort(num,left, mid);

      mergeSort(num,(mid + 1), right);
      
      //merge the sorted arrays

      merge(num, left, mid, right);

    }
}

void MergeSort::printArray(vector<int>& nums)
{
    
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }
 
}

int main ()
{
  vector<int>nums={12,66,71,34,54,67,54};
  
  int n=nums.size();
  
  //calling function to print unsorted array
  cout<<"unsorted array:"<<" "<<endl;
  
  //creating object for the class
  
  MergeSort obj(0, n-1);
  
 
  obj.printArray(nums);
  
  cout<<endl;
  //calling function to sort the array
  
  obj.mergeSort(nums, 0, n-1);
  //calling functionto print sorted array
  
  cout<<"Sorted array:"<<" "<<endl;
  
  obj.printArray(nums);
  

  return 0;
}

