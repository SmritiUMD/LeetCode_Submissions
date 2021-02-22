/******************************************************************************

@author - Smriti Gupta
@date created- Feb 22,21
*******************************************************************************/

#include <vector>
#include <iostream>

using namespace std;

//dynamic programming - O(n) solution
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0) return 0;
        //keeping a track of min_so_far and max_so_far
        int min_so_far=nums[0];
        int max_so_far=nums[0];
        int result=max_so_far;
        
        
        for(int i=1;i<nums.size();i++){
            int curr=nums[i];
            int temp_max= max(curr,max(curr*max_so_far, curr*min_so_far));
            min_so_far=min(curr,min(curr*max_so_far, curr*min_so_far));
            
            max_so_far=temp_max;
            result=max(max_so_far, result);
        }
        return result;
        
    }
};

int main()
{
    Solution obj;
    vector<int>nums{2,3,1,2,4,3};
    
    
    cout<<obj.maxProduct(nums);

    return 0;
}
