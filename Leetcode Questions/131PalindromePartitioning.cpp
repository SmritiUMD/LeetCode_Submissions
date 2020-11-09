/******************************************************************************
@author- Smriti Gupta
@date created- November 9,20
*******************************************************************************/

#include<bits/stdc++.h>

using namespace std;

class Solution {
    
    bool check_palindrome(string s, int low, int high)
    {
       while(low<high){
           if(s[low++]!=s[high--]) return false;
       }
        return true;
    }
void dfs(vector<vector<string>>& result, vector<string>& temp, string& s, int start){
    if(start>=s.size()) result.push_back(temp);
    for(int end=start;end<s.size();end++){
        if(check_palindrome(s,start,end)){
            temp.push_back(s.substr(start,end-start+1));
            dfs(result,temp,s,end+1);
            temp.pop_back();
        }
    }
}
    
    
     
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>temp;
        dfs(result,temp,s,0);
        return result;
               
    }
};


int main()
{
    string word = "aab";
    Solution s;
    vector<vector<string>>result=s.partition(word);
    for(auto x:result){
        cout<<'{';
        for(auto y:x){
            cout<<'"'<<y<<'"'<<',';
        }
        cout<<'}'<<endl;
    }

    return 0;
}
