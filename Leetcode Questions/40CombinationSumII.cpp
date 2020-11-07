/******************************************************************************
@author- Smriti Gupta
@date created- Novemeber 7,20

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
    private:
    void backtrack(vector<int>& temp,vector<vector<int>>& result, int start, vector<int>& candidates, int remain_sum){ 
        if(remain_sum==0)
        {
            result.push_back(temp);
            return;
        }
        else if(remain_sum<0)
        {
            return;
            
        }
        
        else{
            
            for(int i=start;i<candidates.size();i++)
            {
                if(candidates[i]<=remain_sum)
                {
                    temp.push_back(candidates[i]);
                    backtrack(temp, result,i+1,candidates,remain_sum-candidates[i]);
                    temp.pop_back();
                    //at every iteration check for duplicates
                    while( i<candidates.size()-1 &&  candidates[i+1]==candidates[i])
                    {
                        i++;
                    }
                }
            }
        }
    }
       
  
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //to remove duplicates sort the array first
        sort(candidates.begin(), candidates.end());
         vector<vector<int>>result;
            vector<int>temp;
            backtrack(temp, result,0,candidates, target);
            
            return result;
        
        
    }
};

int main()
{
    vector<int>candidates={10,1,2,7,6,1,5};
    int target=8;
    Solution s;
    vector<vector<int>>result=s.combinationSum2(candidates, target);
    
    for(int i=0;i<result.size();i++){
        cout<<'{';
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<',';
        }
        cout<<'}'<<endl;
        
    }

    return 0;
}
