/******************************************************************************
@author- Smriti Gupta
@date created- November 3,20
*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<2) return 0;
        
//         it will keep a track that is someone can reach last index or not
        int max_pos=nums[0];
//         maximum position reachable during current step
        int max_steps=nums[0];
        int jumps=1;
        for(int i=1;i<nums.size();i++){
            
            if(max_steps<i){
//                 one needs more jumps
                jumps++;
//                 to minimize the number of jumps choose the longest possible
                max_steps=max_pos;
                // cout<<max_steps<<"maxsteps"<<jumps<<"jumps";
            }
//             update
           max_pos=max(max_pos,nums[i]+i);
                
            
        }
        cout<<jumps;
        return jumps;
        
    }
};

int main()
{
 vector<int>nums={2,3,1,1,4};
 Solution s;
 s.jump(nums);

    return 0;
}
