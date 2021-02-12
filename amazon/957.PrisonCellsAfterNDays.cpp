/******************************************************************************
@author - Smriti Gupta
@date - Feb 11,21
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;
/*
Instead of calculating N number of times, i am storing every state to detect the cycle
to reduce computations
/*

class Solution {
    
    private:
    //function to calculate new day combination
    vector<int>nextDay(vector<int>cells){\
        vector<int>result(cells.size(),0);
         for(int i=1;i<cells.size()-1;i++){
            result[i]=cells[i-1]==cells[i+1] ? 1:0;
        }
         result[cells.size()-1]=0;
        return result;
   }
    
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int>temp=cells;
        //mapping every state with current value of N
        
        map<vector<int>,int>seen;
        bool forward =false;
        
        for every new day we will check if this cells has already occured or not.
        while(N>0){
            if(!forward){
                vector<int>curr_state=cells;
                if(seen.find(curr_state)!=seen.end()){
                    N%=seen[curr_state]-N;
                }
                else{
                    seen.insert({curr_state,N});
                }
            }
            if(N>0){
                N--;
                cells=nextDay(cells);
            }
           
            
        }
       
  
        return cells;
        
    }
};




int main()
{
    vector<int>cells = {0,1,0,1,1,0,0,1};
    int N = 7;
   
   vector<int>result;
   Solution obj;
   
   result=obj.prisonAfterNDays(cells, N);
   cout<<"{";
   for(auto a:result){
       cout<<a<<",";
   }
   cout<<"}";

    return 0;
}
