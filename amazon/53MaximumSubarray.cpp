/******************************************************************************
@author - Smriti Gupta
@date created- March 4,21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1) 
            return nums[0];
      int max_sum=nums[0];
        int curr_sum=nums[0];
        for(int i=1;i<nums.size();i++){
            curr_sum=max(nums[i],curr_sum+nums[i]);
            max_sum=max(curr_sum,max_sum);
        }
        return max_sum;
    }
};
int main()
{
    Solution obj;
    vector<int>nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<<obj.maxSubArray(nums);

    return 0;
}
