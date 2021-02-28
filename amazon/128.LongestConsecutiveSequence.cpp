/******************************************************************************
@author - Smriti Gupta
@date created- Feb 28,21
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
/*
class Solution {
   
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        
        sort(nums.begin(),nums.end());
        int i=0;
        int j=i+1;
        int current_len=1;
        int longest_len=1;
        /*
        
        
        at every index we will check if the consecutive numbers are not same 
        and if their difference is dfference is equal to 1 - update current_len
        //if yes- update longest length
        while(j<nums.size() && i<j ){
            if(nums[j]!=nums[i]){
                if(nums[j]-nums[i]==1){
                    current_len++;
                }
            else{
                longest_len=max(longest_len,current_len);
                current_len=1;
            }
        }
            i++;
            j++;
        }
        
       
        return max(longest_len,current_len);
//         // complexity=o(nlogn) because of sorting
            
    }
};
*/


// using hash maps 
class Solution {
   
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
       
        int longest_len=0;
        set<int>seen;
      //set will take care of duplicates
        for(auto num:nums){
            seen.insert(num);
        }
        
        for(auto num:nums){
          /*
          at every index we will check if the num-1 exists in set or not
          if not then we can start the sequence and keep counting till the num+1 exists in the set
          and updating the longest len
          */
            if(seen.find(num-1)==seen.end()){
                int current_sum=num;
                int current_len=1;
                while(seen.find(current_sum+1)!=seen.end()){
                    current_sum++;
                    current_len++;
                }
                longest_len=max(longest_len,current_len);
            }
        }
       return longest_len;
            
    }
};
// complexity - O(n)





int main()
{
    vector<int>nums={0,3,7,2,5,8,4,6,0,1};
    Solution obj;
    cout<<obj.longestConsecutive(nums);
    return 0;
}
