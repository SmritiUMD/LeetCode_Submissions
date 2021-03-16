/******************************************************************************
@author - Smriti Gupta
@date created - March 15, 21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class MedianFinder {
    
    /*finding median - O(1) time - top elements are directly excessible.
    At worst, there are three heap insertions and two heap deletions from the top. Each of these takes about O(logn) time.
    total - O(log n)
    space - O(n)
    Maintaining the order while insertion is a good technique to avoid O(nlogn)  for sorting 
    */
public:
    //low will contain all the smaller numbers 
    priority_queue<int>low; // max heap - largest value on the top
    //it will contain all the element greater than  low.top()
    priority_queue<int, vector<int>, greater<int>>high; // min hip - smallest value on the top
    MedianFinder() {
        
    }
    
    void addNum(int num) {
       low.push(num);
        //to maintain the balance,remove the element from low- largest and add it to high
        high.push(low.top());
        low.pop();
        //if size of low is small then remove from high and balance
        if(low.size()<high.size()){
            low.push(high.top());
            high.pop();
        }
        
    }
    
    double findMedian() {
      
        return low.size()>high.size() ? low.top() : (double)(low.top()+high.top())*0.5;
        }
        
    
};



int main()
{

   MedianFinder* obj = new MedianFinder();
   obj->addNum(2);
   cout<<obj->findMedian();
 
  
    return 0;
}
