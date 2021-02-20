/******************************************************************************
@author- Smriti Gupta
@date created= Feb 20,2021
           
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) {
        unordered_map<int,int>count;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }
        int groups=nums.size()/K;
        for(auto c:count){
            //one group cant have same elements(we need to make sequence increasing)
            
            if(c.second/groups>1) return false;
            //to check if frequecny is equal to number of groups
            if(c.second/groups==1 && c.second%groups>0) return false;
        }
        
        
        return true;
    }
};

int main()
{
    Solution obj;
    int K=3;
    vector<int>nums={1,2,2,3,3,4,4};
    obj.canDivideIntoSubsequences(nums, K);

    return 0;
}
