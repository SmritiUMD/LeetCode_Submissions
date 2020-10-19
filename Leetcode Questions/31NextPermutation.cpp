/******************************************************************************
@author-Smriti Gupta
@date created- October 19,2020

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

class Solution {
    
public:
 void nextPermutation(vector<int>& nums);
 void print(vector<int>& nums);
 };

     void Solution::nextPermutation(vector<int>& nums) {
        if(nums.size()==1) return;
        int i=nums.size()-1;
        while(i>0){
            if(nums[i]>nums[i-1]){
                int k=i;//loop onto the array ahead to check for a bigger number than the current
               
                int idx=i;//to store the index
                while(k<nums.size())
                { // check if the value at k is bigger than {i-1}th but less than ith
                    if(nums[k]>nums[i-1] && nums[k]<nums[i])
                    {
                        idx=k;//new index of bigger value to swap
                    }
                    k++;
                }
                swap(nums[i-1],nums[idx]);
                break;
            }
            i--;
        }                                     
        sort(nums.begin()+i,nums.end());
        }
    void Solution::print(vector<int>& nums){
    for(int i=0;i<nums.size();i++)
    {
    cout<<nums[i]<<" ";
    }
    }
  

int main()
{
    vector<int>x={1,2,3};
    Solution obj;
    obj.nextPermutation(x);
    obj.print(x);    

    return 0;
}
