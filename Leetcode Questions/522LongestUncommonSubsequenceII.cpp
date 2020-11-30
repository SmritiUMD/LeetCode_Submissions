/******************************************************************************

@author- Smriti Gupta
@date created - Nov 30,20
*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool check(string &a, string &b){
       int j=0;
       int i=0;
       int n=a.length();
        int m=b.length();
        while(j<m)
        {
            if(a[i]==b[j])
                i++;
            j++;
        }
        return i==n;
    }
public:
    int findLUSlength(vector<string>& strs) {
        int result=-1;
        int n=strs.size();
        if(!n) return n;
        for(int i=0;i<n;i++){
            int count=0; 
            int len=strs[i].size();
            for(int j=0;j<n;j++)
               if(check(strs[i],strs[j]))
                   count++;
            if(count==1){
                result = max(result, len) ;
                // cout<<result<<" "<<len;
            }
        }
        return result;
    }
};
int main()
{
    Solution sort;
    vector<string> s={"aba", "cdc", "eae"};
    cout<<sort.findLUSlength(s);

    return 0;
}
