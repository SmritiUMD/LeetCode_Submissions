/******************************************************************************
@author - Smriti GUpta
@date created = Feb 17,21

*******************************************************************************/



#include <bits/stdc++.h>

using namespace std;

class Solution{
    
public:
int finalinstance(vector<int> &averageUtil, int &instances){
    
    for(int i=0; i<averageUtil.size();i++){
        if(averageUtil[i]<25 &&instances>1){
            // cout<<averageUtil[i]<<endl;
            instances/=2;
            i+=10;
            
            
        }
        else if(i<averageUtil.size() && averageUtil[i]>60 && instances<200000){
            //  cout<<averageUtil[i];
            instances*=2;
            i+=10;
        }
        
    }
    return instances;
}
};

int main()
{
    Solution obj;
    int instances = 2;
    vector<int>averageUtil = {25, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 76, 80};
    
    cout<<obj.finalinstance(averageUtil, instances);
    return 0;
}



