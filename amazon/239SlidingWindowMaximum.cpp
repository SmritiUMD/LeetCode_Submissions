/******************************************************************************
@author - Smriti Gupta
@date cereated - April 12,2021
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>dp(nums.size()-k+1,0);
        if(k==1)
            return nums;
        int sum=0;
        vector<int>left(nums.size(),0);
        vector<int>right(nums.size(),0);
        left[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            if((i%k)==0){
                left[i]=nums[i];
            }
            else
                left[i]=max(left[i-1],nums[i]);
        }
        right[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            if(i%k==0)
                right[i]=nums[i];
            else
                right[i]=max(right[i+1],nums[i]);
        }
        for(int i=0;i<nums.size()-k+1;i++){
           
            dp[i]=max(left[i+k-1],right[i]);
        }
       return dp; 
    }
};

int main()
{
    Solution obj;
    vector<int>nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    
    obj.maxSlidingWindow(nums, k );
    

    return 0;
}
