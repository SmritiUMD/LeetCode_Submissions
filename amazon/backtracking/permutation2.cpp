/******************************************************************************
@author - Smriti Gupta
@date created - March 11, 21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;



class Solution {
vector<vector<int>>result;
    int n=0;
    vector<int>nums;
    
    void backtrack(int first, vector<int>temp){
        // use a set to keep a track of duplicates
        set<int>seen;
        if(first==n){
            result.push_back(temp);
        }
        else{
            for(int i=first;i<n;i++){
                if(seen.find(temp[i])==seen.end()){
                swap(temp[i], temp[first]);
                backtrack(first+1, temp);
                swap(temp[i], temp[first]);
                seen.insert(temp[i]);
                }
        }
    }
        
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int first=0;
        this->n=nums.size();
        this->nums=nums;
        vector<int>temp;
        
        backtrack(0,nums);
        return result;
        
    }
};
 
int main()
{
    Solution obj;
    vector<int>nums={1,2,3};
   
    vector<vector<int>>result=obj.permuteUnique(nums);
    
    for(auto x:result){
        
        for(auto y:x){
            cout<<y<<",";
        }
        cout<<endl;
    }
    
    

    return 0;
}
