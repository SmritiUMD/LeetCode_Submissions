/******************************************************************************
@author - Smriti Gupta
@date created - March 8, 21
*******************************************************************************/


#include <bits/stdc++.h>

using namespace std;


class MinStack {
public:
    /** initialize your data structure here. */
    stack<int>stack_;
    stack<vector<int>>min_stack;
    MinStack() {
        
    }
/*
we are storing frequency with the number on min stack to avoid repeatitions
*/
    void push(int x) {
        //push directly on main stack
        stack_.push(x);
        //check if min stack is empty or  its top is greater than main stack
        //push it with frequency   1
        if(min_stack.empty() || min_stack.top()[0]>x){
            min_stack.push({x,1});
        }
        //if it is equal to top than increment the frequency
        else if(x==min_stack.top()[0]){
            min_stack.top()[1]++;
        }
        
    }
    
    void pop() {
        //if top elements of stacks and min stack are same 
        //remove from both and decrease the frequency
        if(stack_.top()==min_stack.top()[0]){
            vector<int>curr=min_stack.top();
            min_stack.pop();
            min_stack.push({curr[0],curr[1]-1});
            
            
        }
        if(min_stack.top()[1]==0){
            min_stack.pop();
        }
        stack_.pop();
        
    }
    
    int top() {
        return stack_.top();
        
    }
    
    int getMin() {
        return min_stack.top()[0];
        
    }
};

int main(){
// Your MinStack object will be instantiated and called as such:
int x=10;
MinStack* obj = new MinStack();
obj->push(10);
obj->push(5);
obj->pop();
int param_3 = obj->top();
int param_4 = obj->getMin();

    return 0;
}
