/******************************************************************************
@author - Smriti Gupta
@date created- Feb 28,21
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        //start from the end till you find decreasing pair
        while(i>=0 && nums[i+1]<=nums[i]){
            i--;
        }
        // from that index look for a number bigger than nums[index]
        // in the remaining array and swap both the numbers 
        // and sort the remaning sequence
        if(i>=0){
            int  j=nums.size()-1;
            while(j>=0 && nums[j]<=nums[i]){
                j--;
            }
            swap(nums[i],nums[j]);
        }
       sort(nums.begin()+i+1,nums.end()); 
    }
};



int main()
{
    vector<int>nums={1,3,2};
    Solution obj;
    obj.nextPermutation(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<",";
    }
    return 0;
}
