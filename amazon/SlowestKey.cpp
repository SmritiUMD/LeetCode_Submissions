/******************************************************************************
@author -Smriti Gupta
@date created - Feb 13, 21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;



char maxTime(vector<vector<int>>& keyPressedTimes){
    
    priority_queue<pair<int,char>>pq;
    pq.push({keyPressedTimes[0][1],(char)keyPressedTimes[0][0]});
    for(int i=1;i<keyPressedTimes.size();i++){
        int key=keyPressedTimes[i][0]+65;
        char ch= (char)key ;
        cout<<keyPressedTimes[i][0];
        int tim=keyPressedTimes[i][1]-keyPressedTimes[i-1][1];
        // cout<<tim<<" "<<ch<<endl;
        pq.push({tim,ch});
    }
    pair<int,char>curr=pq.top();
    
    return curr.second;
}


int main()

{ 
    vector<vector<int>>keyPressedTimes={{0,1},{3,4},{0,8},{2,11}};
    // int num=60;
    // char ch = (char)0; 

    cout<<maxTime(keyPressedTimes);
    return 0;
}

