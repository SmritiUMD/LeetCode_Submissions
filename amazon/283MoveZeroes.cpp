/******************************************************************************
@author - Smriti Gupta
@date created- March 4,21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size=nums.size();
        if(nums.size()==1 && nums[0]==0)
            return;
        int counter=0;
        int i=0;
        while(i<nums.size()){
            if(nums[i]==0){
                nums.erase(nums.begin()+i);
                counter++;
                
            }
            else{
                i++;
            }
        }
        while(counter>0){
            nums.push_back(0);
            counter--;
        }
        
    }
};
int main()
{
    Solution obj;
    vector<int>nums={0,1,0,3,12};
    
    obj.moveZeroes(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<",";
        }
      

    return 0;
}
