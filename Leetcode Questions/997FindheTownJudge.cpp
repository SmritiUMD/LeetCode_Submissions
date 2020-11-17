/******************************************************************************
@author - SMriti Gupta
@date created- November-17,20

   
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        //indegree of judge is N-1 and outdegree in 0
        vector<int>indegree(N+1,0);
        vector<int>outdegree(N+1,0);
        
        for(vector<int> relation:trust){
            indegree[relation[1]]++;
            outdegree[relation[0]]++;
        }
        for(int i=1;i<=N;i++){
            if(indegree[i]==N-1 && outdegree[i]==0){
                cout<<"town judge is"<<" "<<i;
                return i;
            }
        }
        return -1;
    }
};

int main()
{
   
   vector<vector<int>>trust={{1,3},{1,4},{2,3},{2,4},{4,3}};
   
   int N=4;
   Solution s;
   s.findJudge(N,trust);

    return 0;
}
