/******************************************************************************
@author - Smriti Gupta
@date created - March 11, 21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
class Solution {
    vector<string>result;
    int max=0;
    void backtrack(string comb, int open, int close){
        if(comb.size()==2*max){
            result.push_back(comb);
        }
         if(open<max){
            backtrack(comb+'(',open+1,close);
        }
        if(close<open){
            comb+=')';
            backtrack(comb,open,close+1);
        }
       
        
        
    }
public:
    vector<string> generateParenthesis(int n) {
        this->max=n;
        backtrack("",0,0);
        return result;
        
    }
};

int main()
{
    Solution obj;
    int n=6;
    vector<string>result=obj.generateParenthesis(n);
    
    for(auto x:result){
        cout<<x<<",";
    }
    
    

    return 0;
}
