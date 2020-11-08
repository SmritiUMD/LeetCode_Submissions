/******************************************************************************
@author- Smriti Gupta
@date created- Novemeber 7,20
*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
    private:
    void backtrack(vector<int>& temp,vector<vector<int>>& result, int start, vector<int>& candidates, int remain_sum, int k){ 
        if(remain_sum==0 && temp.size()==k)
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
                    backtrack(temp, result,i+1,candidates,remain_sum-candidates[i], k);
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
    vector<vector<int>> combinationSum2(int n, int k ){
       vector<int>candidates={1,2,3,4,5,6,7,8,9};
         vector<vector<int>>result;
            vector<int>temp;
            backtrack(temp, result,0,candidates, n, k);
            
            return result;
        
        
    }
};

int main()
{
    int k=3;
    int n=7;
    Solution s;
    vector<vector<int>>result=s.combinationSum2(n,k);
    
    for(int i=0;i<result.size();i++){
        cout<<'{';
        for(int j=0;j<result[0].size();j++){
            cout<<result[i][j];
        }
        cout<<'}'<<endl;
        
    }

    return 0;
}
