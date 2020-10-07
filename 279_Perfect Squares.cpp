#include <iostream>
#include <vector>

using namespace std;
class Solution {
    
public:
    int n;
    //paramterized constructor
    Solution(int x ){
        n=x;
    }
    void numSquares() {
        vector<int>dp(n+1,577686);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int s=1;s*s<=i;s++){
              dp[i]=min(dp[i],dp[i-s*s]+1);
            }
        }
       cout<<dp[n];
      }
  
};

int main()
{
//object
   Solution obj(10);
   obj.numSquares();
  
    return 0;
}
