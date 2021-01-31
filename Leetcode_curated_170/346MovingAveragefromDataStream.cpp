/******************************************************************************
@author -Smriti Gupta
@date created-January 30,2021
*******************************************************************************/

//Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

//Implement the MovingAverage class:

//MovingAverage(int size) Initializes the object with the size of the window size.
//double next(int val) Returns the moving average of the last size values of the stream.

#include <bits/stdc++.h>
class MovingAverage {
    
    stack<int>s1;
    int size=0;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size=size;
        
    }
    
    double next(int val) {
        s1.push(val);
        stack<int>s2=s1;
        double count=0;
        double sum=0;
        while(!s2.empty() && count<size){
            sum+=s2.top();
            s2.pop();
            count++;
        }
        cout<<sum<<endl;
        return sum/count;
        
    }
};

int main(){
 MovingAverage* obj = new MovingAverage(size);
 double param_1 = obj->next(val);
 cout<<param_1;
   return 0;
 }
