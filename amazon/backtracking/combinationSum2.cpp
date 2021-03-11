/******************************************************************************
@author - Smriti Gupta
@date created - March 11, 21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>>result;
    vector<int>candidates;
    int target;
   /*
   we need to use each number exactly once but there are duplicates.
   To avoid same combinations increment the index after calling backtracking function.
   Time Complexity - O(2^N) - worst case (all the combinations are exhausted)
   O(NlogN)- sorting
   Space- O(N)
   
   
   */
    void backtrack(int remaining_sum, vector<int>temp, int start){
        if(remaining_sum==0){
            result.push_back(temp);
        }
        if(remaining_sum<0)
            return;
        
        for(int i=start;i<candidates.size();i++){
                // add the number to combination
                temp.push_back(candidates[i]);
                // start from current number - repeatition is allowed for same number
                backtrack(remaining_sum-candidates[i] , temp, i+1);
                // remove the number to backtrack
                int curr=temp.back();
                temp.pop_back();
                while( i<candidates.size()-1 && curr== candidates[i+1])
                {
                    i++;
                }
            
        }
        
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        this->candidates=candidates;
        this->target=target;
        vector<int>temp;
        
        backtrack(target,temp, 0);
        
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
