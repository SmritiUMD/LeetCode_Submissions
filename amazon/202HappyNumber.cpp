/******************************************************************************
@author - Smriti Gupta
@date created- March 4,21

*******************************************************************************/

#include <iostream>

using namespace std;

class Solution {
    int num_next(int n){
        int sum=0;
        string num=to_string(n);
        int i=0;
        while(i<num.size()){
            //to extract digits of number
            int div=pow(10,i);
            int x=n/div%10;
            cout<<x<<" ";
            sum+=pow(x,2);
           
            i++;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        //to avoid loops keep a track of already calculated numbers
        //if(we are in cycle -  return false)
        set<int>seen;
        if(n==1)
            return true;
        
        while(n!=1 && seen.find(n)==seen.end()){
            seen.insert(n);
            n=num_next(n);
        }
        if(n==1)
            return true;
        return false;
        
    }
};

int main()
{
    Solution obj;
    int n=19;
    cout<<obj.isHappy(n);

    return 0;
}
