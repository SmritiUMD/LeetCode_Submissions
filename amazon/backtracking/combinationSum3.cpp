/******************************************************************************
@author - Smriti Gupta
@date created - March 11, 21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;



class Solution {
    
    /*k = number of digits
    Time Complexity - O(9!.k/(9-k)!) - In a worst scenario, we have to explore all potential 
    combinations to the very end,
    e second step, we have 8 choices, so on and so forth.
    contant time at each step to process.
    O(k)- at last step to create copy.
    
    Space- O(k) - a list to keep current elements
    O(k)- k recursive stacks for recursion 
    
    
    
    */
    vector<int>candidates;
    vector<vector<int>>result;
    int k;
    private:
    void backtrack(vector<int>& temp, int start, int remain_sum){ 
       
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
                    backtrack(temp,i+1,remain_sum-candidates[i]);
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
    vector<vector<int>> combinationSum3(int k, int n) {
        this->candidates={1,2,3,4,5,6,7,8,9};
        vector<int>temp;
        this->k=k;
        backtrack(temp,0,n);
            
            return result;
        
        
    }
};
 
int main()
{
    Solution obj;
    int k=3;
    int n=7;
   
    vector<vector<int>>result=obj.combinationSum3(k,n);
    
    for(auto x:result){
        
        for(auto y:x){
            cout<<y<<",";
        }
        cout<<endl;
    }
    
    

    return 0;
}
