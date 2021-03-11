/******************************************************************************
@author - Smriti Gupta
@date created - March 11, 21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
   /*
   we need to use each number exactly once but there are duplicates.
   To avoid same combinations increment the index after calling backtracking function.
   Time Complexity - O(2^N) - worst case (all the combinations are exhausted)
   O(NlogN)- sorting
   Space- O(N)
   
   
   */
    private:
    void backtrack(vector<int>& temp,vector<vector<int>>& result, int start, vector<int>& candidates, int remain_sum){ 
        if(remain_sum==0){
            result.push_back(temp);
            return;
        }
        else if(remain_sum<0){
            return;
            
        }
        
        else{
            
            for(int i=start;i<candidates.size();i++)
            {
                if(candidates[i]<=remain_sum){
                temp.push_back(candidates[i]);
                backtrack(temp, result,i+1,candidates,remain_sum-candidates[i]);
                int curr=temp.back();
                temp.pop_back();
                    
                while( i<candidates.size()-1 && curr== candidates[i+1])
                {
                    i++;
                }
             }
            }
        }
    }
       
  
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
         vector<vector<int>>result;
            vector<int>temp;
            backtrack(temp, result,0,candidates, target);
            
            return result;
        
        
    }
};
int main()
{
    Solution obj;
    int k=7;
    vector<int>candidates={10,1,2,7,6,1,5};
    vector<vector<int>>result=obj.combinationSum2(candidates,k);
    
    for(auto x:result){
        
        for(auto y:x){
            cout<<y<<",";
        }
        cout<<endl;
    }
    
    

    return 0;
}
