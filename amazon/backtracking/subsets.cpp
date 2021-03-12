/******************************************************************************
@author - Smriti Gupta
@date created - March 11, 21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;


class Solution {
      /*Time Complexity- O(N×2^N) to generate all subsets and then copy them into output list.
        Space complexity -O(N). We are using O(N) space to maintain curr, and are modifying curr in-place with backtracking. 
        */
    void backtrack(vector<vector<int>>& result, vector<int>&nums, vector<int>& temp, int index){
        result.push_back(temp);
         for(int i=index;i<nums.size();i++){
            temp.push_back(nums[i]);
            backtrack(result, nums, temp, i+1);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>temp;
        backtrack(result, nums, temp, 0);
        
        
        
       return result; 
    }
};
int main()
{
    Solution obj;
    vector<int>nums={1,2,3};
   
    vector<vector<int>>result=obj.subsets(nums);
    
    for(auto x:result){
        
        for(auto y:x){
            cout<<y<<",";
        }
        cout<<endl;
    }
    
    

    return 0;
}
