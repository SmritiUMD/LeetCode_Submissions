/******************************************************************************
@author- Smriti Gupta
@date created- February 1,21
*******************************************************************************/

/**Design a max stack data structure that supports the stack operations and supports finding the stack's maximum element.

Implement the MaxStack class:

MaxStack() Initializes the stack object.
void push(int x) Pushes element x onto the stack.
int pop() Removes the element on top of the stack and returns it.
int top() Gets the element on the top of the stack without removing it.
int peekMax() Retrieves the maximum element in the stack without removing it.
int popMax() Retrieves the maximum element in the stack and removes it. If there is more than one maximum element, only remove the top-most one.
**/


#include <bits/stdc++.h>

using namespace std;

class MaxStack {
public:
  
    vector<int>stack;
    
    void push(int x) {
        stack.push_back(x);
        
    }
    
    int pop() {
        int back=stack.back();
        stack.pop_back();
        return back;
        
    }
    
    int top() {
        return stack.back();
        
    }
    
    int peekMax() {
        if(stack.size()==1){
            return stack.back();
        }
        vector<int>s=stack;
        sort(s.begin(), s.end());
        return s.back();
        
    }
    
    int popMax() {
        if(stack.size()==1){
            int back=stack.back();
            stack.pop_back();
            return back;
        }
        vector<int>s=stack;
        sort(s.begin(), s.end());
        int back=s.back();
        s.pop_back();
        int index=0;
        for(int i=0;i<stack.size();i++){
            if(stack[i]==back){
                index=i;
            }
        }
   
        stack.erase(stack.begin()+index);
        // cout<<index<<stack.size()<<stack[0]<<stack[1];
        return back;
        
    }
};

int main(){
    
 MaxStack obj;
 obj.push(5);
 obj.push(1);
 obj.push(5);
 cout<<"popped element"<<"-"<<obj.pop()<<endl;
 cout<<"top element"<<"-"<<obj.top()<<endl;
 cout<<"peekMax"<<"-"<<obj.peekMax()<<endl;
 cout<<"popMax"<<"-"<<obj.popMax()<<endl;
 return 0;
 
}

 

