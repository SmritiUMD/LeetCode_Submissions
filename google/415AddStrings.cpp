/******************************************************************************
@author -Smriti Gupta
@date created-Dec 1,20
*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
       string res;
        int sum=0;
        int c=0;
        int p1=num1.size()-1;
        int p2=num2.size()-1;
        while(p1>=0|| p2>=0){
            int x1=p1>=0?num1[p1]-'0':0;
            int x2=p2>=0?num2[p2]-'0':0;
            sum=(x1+x2+c);
            c=sum/10;
            sum=sum%10;
            res.push_back('0'+sum);
            p1--;
            p2--;
        }
        if(c){
            res.push_back('0'+c);
        }
        
       
        reverse(res.begin(),res.end());
        return res;
     }
};

int main()
{
    Solution s;
    cout<<"Sum of strings is: "<<s.addStrings("0","0");

    return 0;
}
