/******************************************************************************
@author- Smriti Gupta
@date created- October 21,2020
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void checkSubarraySum(vector<int>& nums, int k) {
        //to store sum and sum%k
        map<int,int>data;
        int sum=0;
        data.insert(pair<int,int>(0,-1));
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            
            if(k!=0) sum=sum%k;
           
            if(data.find(sum)!=data.end()){
                if(i-data[sum]>1)
                    cout<<true;
                    return;
                }
                else{
                    data.insert(pair<int,int>(sum,i));
                }
            }
        
        
        cout<<false;
        return;
    }
};


int main()
{
    vector<int>x={2,3,4,1,2,3);
    int k=5;
    Solution s;
    s.checkSubarraySum(x,k);

    return 0;
}
