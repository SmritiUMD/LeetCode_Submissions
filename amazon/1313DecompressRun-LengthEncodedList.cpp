/******************************************************************************
@author - Smriti Gupta
@date created - March 5, 2021
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int>result;
        int counter=nums[0];
        for(int i=1;i<nums.size();i++){
            if(i%2==0){
                counter=nums[i];
            }
            else if (i%2==1)
            {
                // cout<<i;
                while(counter>0){
                    result.push_back(nums[i]);
                    counter--;
                }
            }
        }
        
      return result;  
    }
};
 
int main()
{
    Solution obj;
    vector<int>arr = {5,7,0,8,8,10};
   
    vector<int>result=obj.decompressRLElist(arr);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<",";
    }


    return 0;
}
