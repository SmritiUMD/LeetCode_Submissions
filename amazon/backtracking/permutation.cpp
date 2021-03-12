/******************************************************************************
@author - Smriti Gupta
@date created - March 11, 21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;



class Solution {
    /*Time Complexity - N!/(N-1)! - one performs N(N - 1) ... (N - k + 1)N(N−1)...(N−k+1) oprations
    Space- O(N!)- keep N! solutions
    
    */
    vector<vector<int>>result;
    void backtrack(int index, vector<int>& nums){
        if(index==nums.size()){
            result.push_back(nums);
        }
        
        for(int i=index; i<nums.size();i++){
            swap(nums[i],nums[index]);
            backtrack(index+1, nums);
            //since we are making changes to original nums array
           // we need to revert the changes after saving the copy otherwise
               // results will be wrong
               
            swap(nums[i],nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
      
        backtrack(0,nums);
        return result;
        
    }
};
 
int main()
{
    Solution obj;
    vector<int>nums={1,2,3};
   
    vector<vector<int>>result=obj.permute(nums);
    
    for(auto x:result){
        
        for(auto y:x){
            cout<<y<<",";
        }
        cout<<endl;
    }
    
    

    return 0;
}
