/******************************************************************************
@author - Smriti Gupta
@date created- Feb 8,2021
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
class Solution {
     vector<string>ans;
    int max=0;
    private:
    void backtrack(string curr, int open, int close){
        if(curr.size()==2*max){
            ans.push_back(curr);
            return;
        }
        if(open<max){
            backtrack(curr+"(", open+1,close);
        }
        if(close<open){
            backtrack(curr+")", open, close+1);
        }
    }
public:
//using backtracking
    vector<string> generateParenthesis(int n) {
        max=n;
       
        backtrack("",0, 0);
        return ans;
        
    }
};

int main()
{
    
    int n=3;
    Solution obj;
    vector<string>result=obj.generateParenthesis(n);
    
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<",";
    }
    return 0;
}
