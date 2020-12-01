/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    string reformat(string s) {
        string alpha="";
        string digit="";
        string result="";
        int i=0;
        for(i=0;i<s.size();i++){
            if(isdigit(s[i])){
                digit+=s[i];
            }
            else{
                alpha+=s[i];
            }
        }
        string temp="";
       
        if(alpha.size()<digit.size()){
            temp=alpha;
            alpha=digit;
            digit=temp;
        }
        if(alpha.size()-digit.size()>1) return "";
//         iterating over max(alpha.size(),digit.size() and appending the extra char at last)
        for(i=0;i<digit.size();i++){
                result+=alpha[i];
                result+=digit[i];
        }
        if(alpha.size()>digit.size()){
            result+=alpha[i];
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout<<"Reformated string is: "<<s.reformat("a0b1c2");

    return 0;
}
