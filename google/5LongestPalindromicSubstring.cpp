#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int expand(string s, int left, int right){
        int L=left;
        int R=right;
        while(L>=0 && R <s.size() && s[L]==s[R]){
            L--;
            R++;
        }
        return R-L-1;
    }
    
public:
    string longestPalindrome(string s) {
        if(s.size()<1 ) return " ";
        int start =0;
        int end=0;
        for(int i=0;i<s.size();i++){
            int len1=expand(s,i,i);
            int len2=expand(s,i,i+1);
            int len=max(len1,len2);
            if(len>end-start){
                start=i- (len-1)/2;
                end=i+len/2;
            }
        }
        return s.substr(start,end-start+1);
        
        
    }
};
int main(){

Solution o;
string s = "cbbd";
cout<<o.longestPalindrome(s);
};
