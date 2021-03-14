/******************************************************************************
@author- Smriti Gupta
@date created - March 14,21

*******************************************************************************/

#include <bots/stdc++.h>

using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
                              //north,east, south, west
        vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        int idx=0;
        int i=0;
        int j=0;
        
        for (auto x:instructions){
            if(x=='R'){
                idx=(idx+1)%4;
            }
            else if(x=='L'){
                idx=(idx+3) % 4;
            }
            else{
                i+=dir[idx][0];
                j+=dir[idx][1];
            }
        }
        return (i==0 && j==0) || idx!=0;
        
    }
};

int main()
{
    Solution obj;
    string instructions="GGLLRR";
    cout<<obj.isRobotBounded(instructions);
    return 0;
}
