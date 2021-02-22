/******************************************************************************
@author - Smriti Gupta
@date created - Feb 22,21

*******************************************************************************/

#include <vector>
#include <iostream>

using namespace std;

#define INT_MAX 24242
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        /*
        time - O(n)
        int n=nums.size();
        int ans=INT_MAX;
        int left=0;
        int sum=0;
        //using 2 pointers to adjust the size of subarray till the 
        //sum of elements is greater or equal to target
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>=target){
                cout<<i<<left<<" ";
                ans=min(ans,i+1-left);
                sum-=nums[left++];
                cout<<left;
                
            }
            cout<<endl;
        }
       */
        
         // time- O(n^2)
        vector<int>sum(nums.size(),0);
        sum[0]=0;
        for(int i=1;i<nums.size();i++){
            sum[i]=sum[i-1]+nums[i];
        }
        int ans=INT_MAX;
        
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                int s=sum[j]-sum[i]+nums[i];
                if(s>=target){
                    ans = min(ans, j-i+1); 
                    break;
                }
            }
        }
        return (ans!=INT_MAX) ? ans:0;
       
    }
};

int main()
{
    Solution obj;
    vector<int>nums{2,3,1,2,4,3};
    int target = 7;
    
    cout<<obj.minSubArrayLen(target , nums);

    return 0;
}
