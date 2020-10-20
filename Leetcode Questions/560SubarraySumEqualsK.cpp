/******************************************************************************
@author Smriti Gupta
@date created- October 11,2020
*******************************************************************************/

#include<bits/stdc++.h> 

using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int counter=0;
        int sum=0;
        //to store the sum and number of times the sum appeared
        map<int,int>data;
        
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum==k)
            {
                counter++;
            }
            //if sum already exist in map, increase the frequency and counter also
            if(data.find(sum-k)!=data.end())
                counter+=data[sum-k];
                data[sum]++;
            
        }
        cout<<counter; 
    }
};

int main()
{
    vector<int>y={1,1,1};
    int k=2;
    Solution s;
    s.subarraySum(y,k);

    return 0;
}
