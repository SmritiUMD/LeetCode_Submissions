/******************************************************************************
@author - Smriti Gupta
@date created - March 9, 21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<string,int>p;
        p.insert({"I",1});
        p.insert({"V",5});
        p.insert({"X",10});
        p.insert({"L",50});
        p.insert({"C",100});
        p.insert({"D",500});
        p.insert({"M",1000});
       
        
        int i=0;
        int num=0;
        while(i<s.size()){
            string x=s.substr(i,1);
            int val=p[x];
            int next_val=0;
            if(i+1<s.size()){
                next_val=p[s.substr(i+1,1)];
            }
            if(val<next_val){
               num+=next_val-val;
                i+=2;
            }
            else{
                num+=val;
                i++;
            }
        }
        return num;
    }
};

int main()
{
    string x="IIVV";
    Solution obj;
    cout<<obj.romanToInt(x);

    return 0;
}
