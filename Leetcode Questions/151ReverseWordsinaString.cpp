/******************************************************************************
@Author - Smriti Gupta
@Date Created - December 16, 20
*******************************************************************************/

#include <iostream>

#include<bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    string reverseWords(string s) {
// 
        string word, result;
        stringstream ss(s);
        while(ss>>word){
            result=word+" "+result;
        }
        return result.substr(0,result.size()-1);
    }
};



int main()
{
    Solution obj;
    string s= "the sky is blue";
    cout<<obj.reverseWords(s);

    return 0;
}
