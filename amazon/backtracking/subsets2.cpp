/******************************************************************************
@author - Smriti Gupta
@date created - March 11, 21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;


class Solution {
    
void backtrack(vector<vector<int>>& result, vector<int>&nums, vector<int>& temp, int index){
        result.push_back(temp);
    
         for(int i=index;i<nums.size();i++){
            temp.push_back(nums[i]);
            backtrack(result, nums, temp, i+1);
            int curr=temp.back();
            temp.pop_back();
             // keep incrementing the index till adjacent elements are same
            while(i<nums.size()-1 && curr==nums[i+1]){
                i++;
            }
             
        }
    }
public:
     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>temp;
         //sort to put all the duplicates adjacent to each other
        sort(nums.begin(),nums.end());
        backtrack(result, nums, temp, 0);
        
        
        
       return result; 
    }
};


int main()
{
    Solution obj;
    vector<int>nums={1,1,2,3,1,1};
   
    vector<vector<int>>result=obj.subsetsWithDup(nums);
    
    for(auto x:result){
        
        for(auto y:x){
            cout<<y<<",";
        }
        cout<<endl;
    }
    
    

    return 0;
}
