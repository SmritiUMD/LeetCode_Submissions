/******************************************************************************
@author- Smriti Gupta
@date created- February 1,21
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;


void swap(int *x, int *y);

class minHeap{
    int *ptr;
    int capacity;
    int heap_size;
    
    public:
    
    minHeap(int capacity);
    
    // returns parent node of i index 
    int parent(int i){ return (i-1)/2 ;}
    
    void minHeapify(int i);
    
    //returns left child node of given index
    int left(int i){ return (2*i +1);}
    
    // returns right child node of given inex
    int right(int i){ return (2*i +2);}
    
    // removes minimum element from heap- O(log N)
    //need to maintain heap property after removal
    // call heapify
    int extract_min();
    
    
    //decreases the value of the key
    //if the decreased value is less than parent that need to fix - O(log N)
    void decreaseKey(int i, int val);
    
    //return minimum element of heap O(1)
    int getMin() { return ptr[0] ;}
    
    // first replae the key with min possible value and then use extract min to remove it
    // O(log N)
    void deleteKey(int i);
    
    // adding key at the root while maitaining heap property
    void insertKey(int k);
    
};

minHeap::minHeap(int capacity){
    this->heap_size=0;
    this->capacity=capacity;
    ptr = new int[capacity];
}

void minHeap::insertKey(int k){
    if(heap_size==capacity){
        cout<<"capacity reached"<<endl;
        return;
    }
    heap_size++;
    int i=heap_size-1;
    ptr[i]=k;
    
    //fixing the minHeap property if violated
    while(i!=0 && ptr[parent(i)]>ptr[i]){
        swap(&ptr[i] , &ptr[parent(i)]);
        i=parent(i);
    }
    
}

int minHeap::extract_min(){
    if(heap_size<=0)
     return INT_MAX;
    
    if(heap_size==1){
        heap_size--;
        return ptr[0];
    }
    
    //store the min value and remove it from the heap
    int root=ptr[0];
    ptr[0]=ptr[heap_size-1];
    heap_size--;
    minHeapify(0);
    return root;
    
}

void minHeap::decreaseKey(int i, int val){
     
    ptr[i]=val;
    
    //fixing the minHeap property if violated
    while(i!=0 && ptr[parent(i)]>ptr[i]){
        swap(&ptr[i] , &ptr[parent(i)]);
        i=parent(i);
    }
}
      
//this function reduces the key to minimum value and then extract 
//min removes it

void minHeap::deleteKey(int i){
    decreaseKey(i, INT_MIN);
    extract_min();
}
    
    
void minHeap::minHeapify(int i){
    int low=left(i);
    int high=right(i);
    int smallest = i;
    if(low<heap_size && ptr[low] < ptr[high])
        smallest=i;
    if(high < heap_size && ptr[low] < ptr[smallest])
        smallest=high;
        
    if(smallest != i){
        swap(&ptr[i] , &ptr[smallest]);
        minHeapify(smallest);
    }
    
}

void swap( int *x, int *y){
    int temp= *x;
    *x=*y;
    *y=temp;
}

/**

            1
            /\
        6      7
        /\     /
      15  33   45
      
    array - 1, 6, 7, 15, 33, 45(level order traversal)
    
**/

int main(){
    
     
  minHeap h (11);
  h.insertKey(7); 
  h.insertKey(6); 
  h.deleteKey(7); 
  h.insertKey(15); 
  h.insertKey(1); 
  h.insertKey(33); 
  h.insertKey(45); 
  cout <<"Extracted key"<<"-"<< h.extract_min() << " "<<endl; 
  cout << "minimum_element"<<"-"<<h.getMin() << endl; 
  h.decreaseKey(7, 2); 
  cout << "minimum_element after decreasing key 7->2"<<" - "<<h.getMin()<<endl; 
   
 return 0;
 
}

 



