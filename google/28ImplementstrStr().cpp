/******************************************************************************
@author - Smriti Gupta
@date created- Feb 3,21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0) return 0;
        if(haystack=="") return -1;
        int size=0;
        
        for(int i=0;i<haystack.size();i++){
            if(haystack.substr(i,needle.size())==needle)
                return i;
        }
        return -1;
    }
};
int main()
{
    Solution obj;
    cout<<obj.strStr("hello","ll");
    return 0;
}
