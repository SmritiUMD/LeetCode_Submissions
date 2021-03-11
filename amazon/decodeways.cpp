/******************************************************************************
@author- Smriti Gupta
@date created- March 11, 21
*******************************************************************************/



#include <iostream>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        vector<int>dp(s.size()+1,0);
        if(s.size()==0 || s[0]=='0')
            return 0;
        dp[0]=1;
        dp[1]=s.at(0)=='0'? 0:1;
        
        for(int i=2; i<=s.size();i++){
            int one=stoi(s.substr(i-1,1));
            int two = stoi(s.substr(i-2,2));
            
            if(one>=1) dp[i]=dp[i-1];
            if(two>=10 && two<=26) dp[i]+=dp[i-2];
        }
        
       return dp[s.size()]; 
    }
};







int main()
{
    string s="2234";
    Solution obj;
    obj.numDecodings(s);

    return 0;
}
