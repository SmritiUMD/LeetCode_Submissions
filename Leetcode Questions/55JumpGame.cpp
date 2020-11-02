/******************************************************************************
@author- Smriti Gupta
@date created-November2,20

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        int temp = 1;
        for(int i = nums.size() - 2;i >= 0;i--){
            if(nums[i] < temp){
                temp++;
                cout<<nums[i]<<temp<<endl;
            }else{
                temp = 1;
            }
        }
        
        cout<<(nums[0] >= temp);
    }
};

int main()
{
    vector<int>nums={2,3,1,1,4};
    Solution s;
    s.canJump(nums);


    return 0;
}
