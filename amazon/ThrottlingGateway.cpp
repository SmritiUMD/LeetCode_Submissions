/******************************************************************************
@author -Smriti Gupta
@date created - Feb 13, 21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;


int count(int num, vector<int>&requestTime){
int ans = 0 ;
    for(int i = 0 ;  i < requestTime.size(); i++){

        if(i  >2 && requestTime[i] == requestTime[i-3]){
            ans++;
        } else if(i > 19 && (requestTime[i] - requestTime[i-20]) <10){
            ans++;
        } else if( i > 59 && (requestTime[i] - requestTime[i-60]) <60 ){
            ans++;
        }
    }
    return ans;
}
int main()

{
    int num = 21;

    vector<int>requestTime = {1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7,7};
  
    cout<<count(num, requestTime);
   

    return 0;
}
