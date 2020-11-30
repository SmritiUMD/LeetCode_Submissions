/******************************************************************************

@author- Smriti Gupta
@date created - Nov 30,20
*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int n=0;
        int counter =0;
        for(auto i :s){
            if(i=='R')
                n++;
            else 
                n--;
            if(n==0)
                counter++;
        }
       return counter; 
    }
};
    
int main()
{
    Solution sort;
    string s="RLRRRLLRLL";
    cout<<sort.balancedStringSplit(s);

    return 0;
}
