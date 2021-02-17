/******************************************************************************
@author -Smriti Gupta
@date created - Feb 13, 21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int dist(int x1, int y1,int x2, int y2){
    return (pow((x1-x2),2)+pow((y1-y2),2));
}

int nearestDist(int num,vector<int>x, vector<int>y){
    int distance=6868676;
    
    for(int i=0;i<num-1;i++){
        for(int j=i+1;j<num;j++){
            if(x[i]!=x[j] && y[i]!=y[j])
                distance=min(distance,dist(x[i],y[i],x[j],y[j]));
        }
    }
    return distance;
}

int main()

{
   
   vector<int>x={0,1,2};
   vector<int>y={0,1,4};
   int num=3;
   cout<<nearestDist(num, x, y);
   return 0;
}


