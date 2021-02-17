

/******************************************************************************
@author -Smriti Gupta
@date created - Feb 13, 21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int vacation(vector<int>arr, int k){
    vector<int>minTemp;
    int j, min; 
 
    for (int i = 0; i <= arr.size() - k; i++) 
    { 
        min= arr[i]; 
 
        for (j = 1; j < k; j++) 
        { 
            if (arr[i + j] < min) 
                min = arr[i + j]; 
        } 
        minTemp.push_back(min);
    }
    sort(minTemp.begin(), minTemp.end());
    
    return minTemp[minTemp.size()-1];
} 

int main()

{
   
   vector<int>days={62,64,77,75,71,60,79,75};
   int k=4;
   cout<<vacation(days, k);
   return 0;
}

/*
https://www.geeksforgeeks.org/minimum-and-maximum-of-all-subarrays-of-size-k-using-map/
https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
Using deque- O(n)
*/



