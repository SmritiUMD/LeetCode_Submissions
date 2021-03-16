/******************************************************************************
@author - Smriti Gupta
@date created - March 15, 21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class FreqStack {
public:
    //to store frequency
    map<int,int>freq;
    //for every frequency mapping a stack
    map<int,stack<int>>stack_;
    //keeping a track of maximum frequency
    int max_freq=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        //increment the freq in map
        freq[val]++;
        //update the max_freq
        if(max_freq<freq[val])
            max_freq=freq[val];
        //update the stack for given freq
        stack_[freq[val]].push(val);
        
    }
    
    int pop() {
        //remove the top element for current max_frequency
        int curr=stack_[max_freq].top();
        stack_[max_freq].pop();
        //decrement its frequency in map
        freq[curr]--;
        // if stack is empty, remove the key
        if(stack_[max_freq].empty()){
            stack_.erase(max_freq);
            max_freq--;
        }
       return curr; 
    }
};



int main()
{

  FreqStack* obj = new FreqStack();
  obj->push(5);
  cout<<obj->pop();
  
    return 0;
}
