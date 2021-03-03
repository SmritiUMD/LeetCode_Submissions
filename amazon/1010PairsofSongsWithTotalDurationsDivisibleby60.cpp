/******************************************************************************
@author - Smriti Gupta
@date created - March 2,2020
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int i=0;
        int j=time.size()-1;
        vector<int>remainder(60,0);
        int count=0;
        for(int i=0;i<time.size();i++){
           if(time[i]%60==0){
               //checking the condition if the number if perfectly divisible by 60
               count+=remainder[time[i]%60];
           }
            else{
                //when the  number if greater than or less than 60
                count+=remainder[60-time[i]%60];
            }
            remainder[time[i]%60]++;
        }
        
       return count; 
    }
};

int main()
{
    vector<int>time= {30,20,150,100,40};
    Solution obj;
    cout<<obj.numPairsDivisibleBy60(time);

    return 0;
}
