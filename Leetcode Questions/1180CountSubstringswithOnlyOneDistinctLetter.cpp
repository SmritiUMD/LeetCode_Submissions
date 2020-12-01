/******************************************************************************
@author - Smriti Gupta
@date created - Dec 1,20

*******************************************************************************/

#include <iostream>

using namespace std;

class Solution {
public:
    int countLetters(string S) {
        int l=0;
        int r=0;
        int count=0;
        while(r<S.size()){
           while(S[r]==S[l] && r<S.size()){
            //   cout<<S.at(l)<<" "<<S.at(r)<<endl;
                r++;
            }
            cout<<"yes";
            for(int i=1;i<=r-l;i++){
                count+=i;
                // cout<<count<<endl;
            }
            l=r;
        }
        return count;
    }
};

int main()
{
    Solution s;
    cout<<"Total count is: "<<s.countLetters("aaaba");

    return 0;
}
