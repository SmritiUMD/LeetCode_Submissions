/******************************************************************************
@author - Smriti Gupta
@date created - March 11, 21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>>result;
    int size;
    int n;
    void backtrack(int start, vector<int>temp){
        if(temp.size()==size)
            result.push_back(temp);
        
        for(int i=start; i<=n; i++){
            temp.push_back(i);
            backtrack(i+1,temp);
            temp.pop_back();
        }
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        this->n=n;
        this->size=k;
        backtrack(1,temp);
       return result; 
    }
};

int main()
{
    Solution obj;
    int n=6;
    int k=3;
    vector<vector<int>>result=obj.combine(n,k);
    
    for(auto x:result){
        
        for(auto y:x){
            cout<<y<<",";
        }
        cout<<endl;
    }
    
    

    return 0;
}
