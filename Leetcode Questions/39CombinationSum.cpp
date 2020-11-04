/******************************************************************************
@author - Smriti Gupta
@date created- November 4,20
*******************************************************************************/

#include <bits/stdc++.h> 

using namespace std;

class Solution {
    private:
    void backtrack(vector<int>temp,vector<vector<int>>& result, int start, vector<int>& candidates, int remain_sum){
        if(remain_sum==0){
            result.push_back(temp);
            return;
        }
        else if(remain_sum<0){
            return;
            
        }
        for(int i=start;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            // cout<<candidates[i]<<endl;
            backtrack(temp, result,i,candidates,remain_sum-candidates[i]);
            temp.pop_back();
        }
    }
       
  
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>>result;
            vector<int>temp;
            backtrack(temp, result,0,candidates, target);
            for(int i =0;i<result.size();i++){
                for(int j=i;j<result[0].size();j++){
                    cout<<result[i][j];
                }
                cout<<endl;
            }
            
            return result;
        
        
    }
};
int main()
{
    vector<int>candidates={2,3,6,7};
    int target =7;
    Solution obj;
    obj.combinationSum(candidates,target);
   

    return 0;
}
