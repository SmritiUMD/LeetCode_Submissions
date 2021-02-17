/******************************************************************************
@author - Smriti GUpta
@date created = Feb 17,21
Minimum Container size

*******************************************************************************/



#include <bits/stdc++.h>

using namespace std;




class Solution {
    /*cut the arrary into contigous subarrays and return the minimum sum of max of 
    each subarray.
    */
    //declaring private variable to reduce computation time. I was getting time limit exceeded error
   
    vector<vector<int>>dp;
    vector<int>jobDifficulty;
    private:
    int helper(int d ,int idx){
        
        if(d==1){
            int max_sum=0;
            while(idx<jobDifficulty.size()){
                max_sum=max(max_sum,jobDifficulty[idx++]);
            }
            return max_sum;
        }
        if(dp[d][idx]!=-1) return dp[d][idx];
        int max_sum=0;
        int result=INT_MAX;
        //I am makind d cuts and storing min of sum of all the max elements
        for(int i=idx;i<jobDifficulty.size()-d+1;i++){
            max_sum=max(max_sum, jobDifficulty[i]);
            
            result=min(result, max_sum+helper(d-1, i+1));
        }
        
        return dp[d][idx]= result;
    }
    
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        this->jobDifficulty=jobDifficulty;
        if(d>jobDifficulty.size())
            return -1;
      
        vector<vector<int>>x(d+1, vector<int>(jobDifficulty.size(),-1));
        dp=x;
    
        
        return helper(d, 0);
        
        
    }
};

