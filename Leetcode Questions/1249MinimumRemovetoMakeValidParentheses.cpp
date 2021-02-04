/******************************************************************************
@author - Smriti Gupta
@date created- Feb 3,21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string result="";
        set<int>indexToRemove;
        stack<int>st;
        //keep inserting indices of open brackets into stack
        //for close bracket check if the stack is empty - remove 
        //else pop the index from te stack
        for(int i=0;i<s.size();i++){
            if(s.at(i)=='(')
                st.push(i);
            if(s.at(i)==')'){
                if(st.empty())
                    indexToRemove.insert(i);
                else
                    st.pop();
            }
        }
        while(!st.empty()){
            indexToRemove.insert(st.top());
            st.pop();
    }
        for(int i=0;i<s.size();i++){
            if(indexToRemove.find(i)==indexToRemove.end())
                result+=s.at(i);
        }
        return result;
        
    }
};

int main()
{
    Solution obj;
    cout<<obj.minRemoveToMakeValid("lee(t(c)o)de)");
    return 0;
}
