/******************************************************************************
@author - Smriti Gupta
@date created- November 4,20
*******************************************************************************/

#include <bits/stdc++.h> 

using namespace std;

class Solution {

vector<vector<int>>result;
private:
    void backtrack(vector<int>temp, int n, int start, int k){
        if(temp.size()==k){
            result.push_back(temp);
        }
        for(int i=start;i<=n;i++){
            temp.push_back(i);
            backtrack(temp, n, i+1,k);
            temp.pop_back();
        }
        
    }
    
    
    
public:
    vector<vector<int>> combine(int n, int k) {
       
        vector<int>temp;
        backtrack(temp, n, 1, k);
        
        for(int i =0;i<result.size();i++)
        {
            for(int j=0;j<result[0].size();j++)
            {
                cout<<result[i][j];
            }
                cout<<endl;
            }
            
       return result;     
        
    }
};
       
  

int main()
{
    int n=4;
    int k=2;
    Solution obj;
    obj.combine(n,k);
   

    return 0;
}
