/******************************************************************************
@author -Smriti Gupta
@date created-January 30,2021
*******************************************************************************/
//You are given an inclusive range [lower, upper] and a sorted unique integer array nums, where all elements are in the inclusive range.

//A number x is considered missing if x is in the range [lower, upper] and x is not in nums.
//Each range [a,b] in the list should be output as:
//"a->b" if a != b
//"a" if a == b



#include<bits/stdc++.h>

class Solution {
    private:
    string formRange(int lower, int upper){
        if(lower==upper){
            return to_string(lower);
        }
        else{
            return to_string(lower)+"->"+to_string(upper);
        }
    }
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string>result;
        // nums.push_back(upper);
        if(nums.size()==0){
            result.push_back(formRange(lower,upper));
            return result;
        }
        if(nums[0]>lower){
            result.push_back(formRange(lower,nums[0]-1));
        }
        
        
        for(int i=1;i<nums.size();i++){
           
            if(nums[i]-nums[i-1]>1){
               result.push_back(formRange(nums[i-1]+1, nums[i]-1));
                
            }
        }
        if(upper>nums[nums.size()-1])
            result.push_back(formRange(nums[nums.size()-1]+1,upper));
        
        return result;
    }
};

int main(){
Solution onj;
vector<string>result=obj.findMissingRanges({0,1,3,50,75},0,99);
for(int i=0;i<result.size();i++){
 cout<<result[i]<<endl;
}
    return 0;

}
