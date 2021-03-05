/******************************************************************************
@author - Smriti Gupta
@date created - March 5, 2021
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
  /*Using Binary Search - O(log n)
  Using Linear scan - O(n)
  
  */
    int helper(vector<int>& nums, int target, bool LeftBias){
        int start=0;
        int end=nums.size()-1;
        int i=-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]>target){
                end=mid-1;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else {
                i=mid;
                //adding this part to keep search even if index has already found
                //LeftBias will direct search to left half and will find left most index
                if(LeftBias)
                    end=mid-1;
                else
                    start=mid+1;
            }
        }
        return i;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>result={-1,-1};
        result[0]=helper(nums, target, true);
        result[1]=helper(nums, target,  false);
        
       return result; 
    }
};
int main()
{
    Solution obj;
    vector<int>nums = {5,7,7,8,8,10};
    int target = 8;
    auto result=obj.searchRange(nums, target);
    cout<<result[0]<<","<<result[1];

    return 0;
}
