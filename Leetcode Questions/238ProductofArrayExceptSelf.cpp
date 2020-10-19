/******************************************************************************
@author Smriti Gupta
@date created- October 19,2020

*******************************************************************************/



#include <bits/stdc++.h> 

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>result(nums.size(),1);
        vector<int>left_product(nums.size(),1);
        vector<int>right_product(nums.size(),1);
      // to store the left product starting from 1
        for(int i=1;i<nums.size();i++)
        {
            left_product[i]=nums[i-1]*left_product[i-1];
        }
        // to store the right product starting from the 1
        for(int i=nums.size()-2;i>=0;i--)
        {
            right_product[i]=right_product[i+1]*nums[i+1];
             // cout<<right_product[i]<<endl;
        }
        
       //total product
        for(int i=0;i<nums.size();i++)
        {
            result[i]=right_product[i]*left_product[i];
            cout<<resutl[i];
        }
       
    }
};

int main()
{
    vector<int>x={3,4,5,6,};
    Solution s;
    s.productExceptSelf(x);

    return 0;
}
