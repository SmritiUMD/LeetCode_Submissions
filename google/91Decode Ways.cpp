/******************************************************************************
@author-Smriti Gupta
@date created-October 14,2010

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;


//recursive with memoization
// class Solution {
//     map<int, int>memo;
 
//     int recursive(int index, string str){
//         if(memo.find(index)!=memo.end())
//             return memo[index];
        
//         if(index==str.size())
//                 return 1;
//         if(str[index]=='0')
//             return 0;
//         if(index==str.size()-1)
//             return 1;
            
//         int ans=recursive(index+1, str);
        
//         if(stoi(str.substr(index,2))<=26){
//             ans+=recursive(index+2,str);
//         }
//         memo[index]=ans;
//         return ans;
        
//     }
// public:
//     int numDecodings(string s) {
//         return recursive(0,s);
        
//     }
// };


//iterative with dynamic array
// class Solution {
// public:
//     int numDecodings(string s) {
//         vector<int>dp(s.size()+1,0);
//         if(s.size()==0 || s[0]=='0') return 0;
//         dp[1]=s.at(0)=='0'? 0:1;
//         dp[0]=1;
        
//         for(int i=2;i<=s.size();i++){
//             int one_digit=stoi(s.substr(i-1,1));
//             int two_digit=stoi(s.substr(i-2,2));
//             if(one_digit>=1) dp[i]=dp[i-1];
//             if(two_digit>=10 && two_digit<=26){
//                 dp[i]+=dp[i-2];
//             }
//         }
//         return dp[s.size()];
        
//     }
// };

//constant space solution by using two variables to store [i-1] and [i-2] positions
class Solution {
public:
    int numDecodings(string s) {
      
        if(s.size()==0 || s[0]=='0') return 0;
        int one_back=1;
        int two_back=1;
        for(int i=2;i<=s.size();i++){
            int current=0;
            int one_digit=stoi(s.substr(i-1,1));
            int two_digit=stoi(s.substr(i-2,2));
            if(one_digit>=1) current=one_back;
            if(two_digit>=10 && two_digit<=26){
                current+=two_back;
            }
            two_back=one_back;
            one_back=current;
        }
        return one_back;
        
    }
};

int main()
{
   string s="142";
   
   Solution obj;
   obj.numDecodings(s);

    return 0;
}
