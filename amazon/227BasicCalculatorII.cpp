/******************************************************************************
@author - Smriti Gupta
@date created - April 10,2021
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculate(string str) {
        int len=str.size();
        if(len==0)
            return 0;
        stack<int>s;
        int curr_num=0;
        char operation='+';
        for(int i=0;i<str.size();i++){
            char curr=str[i];
            if(isdigit(curr)){
                curr_num=(curr_num*10)+(curr-'0');
            }
            if(!isdigit(curr) && !iswspace(curr) || i==len-1){
                if(operation=='-'){
                   s.push(-curr_num); 
                }
                else if(operation=='+'){
                    s.push(curr_num);
                }
                else if(operation=='*'){
                    int s_top=s.top();
                    s.pop();
                    s.push(s_top*curr_num);
                }
                else if(operation=='/'){
                    int s_top=s.top();
                    s.pop();
                    s.push(s_top/curr_num);
                }
                operation=curr;
                curr_num=0;
            }
        }
        int result=0;
        while(s.size()!=0){
            result+=s.top();
            s.pop();
        }
        return result;
        
    }
};

int main()
{
    Solution obj;
    string S="3+5/6+2-4";
    cout<<obj.calculate(S);

    return 0;
}
