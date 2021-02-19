/******************************************************************************
@author- Smriti Gupta
@date created -Feb 19,21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        long long mod = 1e9 + 7;
       
        int hor=max(horizontalCuts[0], h-horizontalCuts.back());
        for(int i=1;i<horizontalCuts.size();i++){
            // cout<<horizontalCuts[i]<<hor<<endl;
            hor=max(hor,horizontalCuts[i]-horizontalCuts[i-1]);
        }
        int ver=max(verticalCuts[0], w-verticalCuts.back());
        for(int i=1;i<verticalCuts.size();i++){
            ver=max(ver,verticalCuts[i]-verticalCuts[i-1]);
        }
        return (ver%mod)*(hor%mod) %mod;
        
    }
};

int main()
{
    int h = 5;
    int w = 4; 
    vector<int>horizontalCuts = {1,2,4};
    vector<int>verticalCuts = {1,3};
    
    Solution obj;
    cout<<obj.maxArea(h,w,horizontalCuts, verticalCuts);

    return 0;
}
