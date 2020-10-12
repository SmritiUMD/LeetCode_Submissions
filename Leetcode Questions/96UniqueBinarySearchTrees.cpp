/******************************************************************************
@author-Smriti Gupta
@date created-October 12,2020

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int>G(n+1,0);
        G[0]=1;
        G[1]=1;
        
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                G[i]+=G[j-1]*G[i-j];
            }
        }
        cout<<G[n];
        
    }
};

int main()
{
    int n=0;
    cin>>n;
    
    Solution obj;
    obj.numTrees(n);

    return 0;
}
