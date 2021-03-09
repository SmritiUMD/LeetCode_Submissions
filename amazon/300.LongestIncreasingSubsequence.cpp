/******************************************************************************
@author - Smriti Gupta
@date created - March 8, 21
*******************************************************************************/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        vector<int>dp(nums.size(),0);
        dp[0]=1;
        int max_ans=1;
        for(int i=1;i<dp.size();i++){
            int max_val=0;
            for(int j=0;j<i;j++){
                //updating only when the sequence is increasing
               if(nums[i]>nums[j]) {
                   max_val=max(max_val,dp[j]);
               }
            }
            //if sequence is increasing - value will get incremented
            //otherwise, it will be 1
            dp[i]=max_val+1;
            //keep a track of max length
            max_ans=max(max_ans,dp[i]);
        }
       return max_ans; 
    }
};
int main(){
    vector<int>nums={10,9,2,5,3,7,101,18};
    
    Solution obj;
    
    cout<<obj.lengthOfLIS(nums);
    

    return 0;
}
