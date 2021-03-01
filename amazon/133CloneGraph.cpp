/******************************************************************************
@author - Smriti GUpta
@date created - Feb 28,21
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
     map<Node*, Node*>visited;
public:
//     using DFS
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
      /* 
        keeping a track of visited nodes so that code will not stuck in a loop
        key- node in original graph 
        value - cloned node
        */
        if(visited.find(node)!=visited.end()){
            return visited[node];
        }
        // cloning the current node with a vector to store its neighbors
        Node* clone_node= new Node(node->val, {});
        // adding the cloned_node woth its original node in the map
        visited.insert({node, clone_node});
        /*
        iterating over current node's neighbor's and pushing them 
        into clone_node's neighbor's, at every neighbor making a recursive call to it's neighbors
        */
        for(Node* neighbor:node->neighbors){
            clone_node->neighbors.push_back(cloneGraph(neighbor));
        }
       return clone_node;
        
    }
};

int main()
{
    Solution obj;
    // {{2,4},{1,3},{2,4},{1,3}}
    Node* node= new Node();
  
    Node* n_1= new Node(1);
    Node* n_2= new Node(2);
    Node* n_3= new Node(3);
    Node* n_4=new Node(4);
    node->neighbors={n_1};
    
    n_1->neighbors={n_2, n_4};
    n_3->neighbors={n_2,n_4};
    n_2->neighbors={n_1,n_3};
    n_4->neighbors={n_1,n_3};
    obj.cloneGraph(node);

    return 0;
}
