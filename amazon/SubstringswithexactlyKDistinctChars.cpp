/******************************************************************************
@author - Smriti GUpta
@date created = Feb 17,21

*******************************************************************************/


#include <bits/stdc++.h>

using namespace std;

int uniqueSubstring_k(string s,int K){
    
    int res=0;
   
    for(int i=0; i<s.size();i++){
        int end=i;
        string substr="";
        map<char,int> keys;
        while(end<s.size()){
            substr+= s[end];
            keys[s[end]]++;
            
            if(keys.size()>K){
                break;
            }
            
            if(substr.size()>1 && keys.size()==K){
                res++;
            }
            
             end++;
        }
    }
    
    return res;
}

int main() {
   
   string s = "aabab";
   int k = 3;
   cout<<uniqueSubstring_k(s,k);
    
}
