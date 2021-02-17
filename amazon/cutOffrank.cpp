/******************************************************************************
@author - Smriti GUpta
@date created = Feb 17,21

*******************************************************************************/



#include <bits/stdc++.h>

using namespace std;


int cutoffRank(int cutoffrank, vector<int>& scores, int num){

    sort(scores.begin(), scores.end());
    reverse(scores.begin(),scores.end());
    int rank=1;
    int res=0;
    for(int i=0;i<scores.size();i++){
        if(i==0)
            rank=1;
        else if(scores[i]!=scores[i-1]){
            rank=i+1;
        }
        if(rank<=cutoffrank && scores[i]>0){
            cout<<scores[i];
            res++;
            cout<<res<<"rank"<<rank<<endl;
        }
        else break;
    }
    
    return res;
    
}



int main()
{
    int num = 5;
    vector<int>scores= {2,2,3,4,5 };
    int cutoffrank=4;
    
    cout<<cutoffRank(cutoffrank,scores,num);
    return 0;
}


