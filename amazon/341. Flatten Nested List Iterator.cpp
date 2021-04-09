/******************************************************************************
@author - Smriti Gupta
@date- April 9,21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;


 // This is the interface that allows for creating nested lists.
 // You should not implement it, or speculate about its implementation
 class NestedInteger {
   public:
     // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const;

     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
      int getInteger() const;

     // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
     const vector<NestedInteger> &getList() const;
  };
 

class NestedIterator {
     vector<int>integers;
    int position=0;
    
    void flattenList(vector<NestedInteger>nestedList){
            for(NestedInteger x:nestedList){
                if(x.isInteger()){
                    integers.push_back(x.getInteger());
                }
                else{
                    flattenList(x.getList());
                }
            }
            
        }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
            flattenList(nestedList);
        }
       
    int next() {
        
        return integers[position++];
        
    }
    
    bool hasNext() {
        return position<integers.size();
        
    }
};



int main()
{
   
    NestedIterator i(nestedList);
    while (i.hasNext()) cout << i.next();
    return 0;
}
