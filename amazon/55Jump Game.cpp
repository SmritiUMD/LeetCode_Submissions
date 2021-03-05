/******************************************************************************
@author - Smriti Gupta
@date created - March 5, 2021
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

/*
This is a problem of backtracking. At every index check every step till max step we can take through which we 
can jump till last index.
Modified by using (recursion +  memoization) to keep a track of previous index( if it is good or not i.e., 
last index can be reached from it or not) - Top Down Approach.
The need for recursion can be removed by using a dp array and using 2 for loops- one to check every index and 
other to check all indices before the current index - if we can reach to current from any of previous indices
or not.- Bottom up approach
O(n^2)- time
Greedy - Do a linear scan and keep a track of step needed to reach that index.
O(n) time

*/
/*Greedy Approach
//G
class Solution {

public:
    bool canJump(vector<int>& nums) {
        int steps_needed=1;
        if(nums.size()==1)
            return true;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<steps_needed){
                steps_needed++;
            }
            else
             steps_needed=1;
            
        }
        return nums[0]>=steps_needed;
        
    }
};
*/

/*
//TOp - Down approach 
class Solution {
    // good=0;
    // bad=1
    // unknown=5
    vector<int>memo;
    bool helper(int pos, vector<int>& nums){
        int size=nums.size();
        if(memo[pos]!=5){
            return (memo[pos]==0) ? true : false;
        }
        //maximum jump I can take  is :
        int max_jump= min(pos+nums[pos],size-1 );
        
        //start by taking 1 jump and check till maximum jumps
        
        for(int next_pos = pos+1; next_pos<=max_jump; next_pos++){
            
            if(helper(next_pos,nums)){
                //making every pos true
                memo[next_pos]=0;
                
                return true;
            }
        }
        //if there is no path till last index than make that pos bad index
        memo[pos]=1;
        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        vector<int>m(nums.size(),5);
        memo=m;
        
        nums[nums.size()-1]=0;
        
        return helper(0,nums);
        

    }
};
*/

//Bottom Up - removing need for recursion
 class Solution {
  public:
    bool canJump(vector<int>& nums){
        vector<bool>dp(nums.size(),false);
        dp[0]=true;
        for(int i=1;i<nums.size();i++){
            dp[i]=false;
            for(int j=0;j<i;j++){
                if(dp[j] && nums[j]+j>=i){
                    dp[i]=true;
                    break;
                }
            }
        }
        
        return dp[nums.size()-1];
        
    }
 };
 
int main()
{
    Solution obj;
    vector<int>nums = {5,7,7,8,8,10};
   
    bool result=obj.canJump(nums);
    cout<<result;

    return 0;
}
