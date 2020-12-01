/******************************************************************************
@author-Smriti Gupta
@date create-Dec 1,20

*******************************************************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int p=s.size();
        int len=0;
        while(p>0){
            p--;
            if(s.at(p)!=' '){
                len++;
            }
            else if(len>0){
                return len;
            }
        }
       return len; 
    }
};

int main()
{
    Solution s;
    cout<<"Length of Last Word is: "<<s.lengthOfLastWord("Hello World");

    return 0;
}
