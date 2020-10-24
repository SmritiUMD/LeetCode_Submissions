/******************************************************************************
@author- Smriti Gupta
@date created-October 24,2020

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h> 

using namespace std;

class Solution {
    private:
    void reverse(vector<int>& nums, int start, int end);
    
    public:
    int k;
    vector<int>nums;
    Solution(vector<int>& nums, int k);
    void rotate();
    void print();
};
    
   Solution::Solution(vector<int>& y ,int x):
        k(x),nums(y)
        {
            
        } 
    
    
    void Solution::reverse(vector<int>& x, int start, int end)
    {
        while(start<end)
        {
            int temp=nums[start];
            nums[start]=nums[end];
            nums[end]=temp;
            start++;
            end--;
        }
    }
    

    void Solution::rotate() {
    //this eliminates the risk of the cases when k is more than vector's size
        k%=nums.size();
        //reverse whole 
        reverse(nums,0,nums.size()-1);
        //reverse elemnts upto k from last
        reverse(nums,0,k-1);
        //reverse elements last to k from last
        reverse(nums,k,nums.size()-1);
        
    }
    void Solution::print()
    {
        for(int i=0;i<nums.size();i++)
        {
            cout<<nums[i]<<" ";
        }
    }


int main()
{
   vector<int>nums={1,2,3,4,5,6,7};
   int k=3;
   Solution s(nums,k);
   s.rotate();
   s.print();
   

    return 0;
}
