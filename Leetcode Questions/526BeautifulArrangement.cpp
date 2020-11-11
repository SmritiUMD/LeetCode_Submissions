/******************************************************************************
@author - Smriti Gupta
@date created-November 11,2020
*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/******************************************************Solution 1
 class Solution
 {
 private:

    int counter=0;
    void count(int N, int index, vector<bool>& visited){
        if(index>N){
            counter++;
        }
        for(int i=1;i<=N;i++){
            if(!visited[i] && (index%i==0 || i%index==0))
            {
                visited[i]=true;
                count(N,index+1,visited);
                visited[i]=false;
            }
        }
    }
   public:
    int countArrangement(int N) {
        vector<bool>visited(N+1);
        count(N,1,visited);
        return counter;
        
    }
};
*************************************************/



/*************Solution 2 - Time Limit Exceeded in Leet Code but solution is correct
    int counter=0;
    private:
    bool check(vector<int>& temp){
     for(int i=0;i<temp.size();i++){
            // cout<<i+1<<temp[i]<<endl;
            if(temp[i]%(i+1)==0 || (i+1)%temp[i]==0){
              continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
    void backtrack(vector<int>& temp,int first, int end){
        if(check(temp) && first==end){
            counter++;
             return;
        }
        for(int i=first;i<=end;i++){
            swap(temp[i],temp[first]);
            backtrack(temp,first+1, end);
            swap(temp[i],temp[first]);

        }
    
}
public:
    int countArrangement(int N) {
        vector<int>input(N);
        iota(begin(input),end(input),1);
        backtrack(input,0 ,input.size()-1);
        return counter;
    }
};

*******************************////
using namespace std;

int main()
{
   
    int N=3;
    Solution s;
    cout<<s.countArrangement(N);

    return 0;
}
