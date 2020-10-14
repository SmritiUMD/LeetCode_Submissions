/******************************************************************************
@author-Smriti Gupta
@date created-October 14,2010

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   
public:
    int numDecodings(string s) {
       if(s.size()==0||s[0]=='0') return 0;
        // if(s.size()==1) return 1;
        
        //dp array to store the number of ways
        vector<int>dp(s.size()+1,0);
        dp[0]=1;
        dp[1]=s.at(0)=='0'? 0:1;
        
        for(int i=2;i<=s.size();i++){
            int oneDigit=stoi(s.substr(i-1,1));
            int twoDigit=stoi(s.substr(i-2,2));
            if(oneDigit>=1) dp[i]+=dp[i-1];
            if(twoDigit>=10 && twoDigit<=26) dp[i]+=dp[i-2];
            
        }
        
       cout<<dp[s.size()] ;
    }
};

int main()
{
   string s="142";
   
   Solution obj;
   obj.numDecodings(s);

    return 0;
}
