/******************************************************************************
@author - Smriti Gupta
@date - Feb 11,21
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool isRobotBounded(string instructions) {
        //0-north, 1-east, 2- south, 3-west
        vector<vector<int>>directions={{0,1},{1,0},{0,-1},{-1,0}};
        int x=0; 
        int y=0;
        
        //facing north
        int idx=0;
        
        for(char i:instructions){
            if(i=='L'){
                idx=(idx+3)%4;
            }
            else if(i=='R'){
                //to keep idx in range
                idx=(idx+1)%4;
            }
            else{
                x+=directions[idx][0];
                y+=directions[idx][1];
            }
        }
            
        //after one cycle robot will come back to origin or it will not face north
        return (x==0 && y==0) || (idx!=0);
        
    }
};

int main()
{
    string s = "GGLLGG";
    Solution obj;
    cout<<obj.isRobotBounded(s);

    return 0;
}
