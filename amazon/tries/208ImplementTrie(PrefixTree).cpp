/******************************************************************************
@author - Smriti Gupta
@date created - March 15, 21

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

struct TrieNode{
   TrieNode* children[26]={NULL};
   bool isWord=false;

};


class Trie {
    TrieNode* root;
public:
    /** Initialize your data structure here. */
        
    Trie() {
         root=new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node = root;
        for(char c:word){
            if(node->children[c-'a']==NULL){
                node->children[c-'a']=new TrieNode();
            }
            node=node->children[c-'a'];
        }
        node->isWord=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node= root;
        for(char c: word){
            if(node->children[c-'a']!=NULL){
                node=node->children[c-'a'];
            }
            else{
                return false;
            }
        }
        return node->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node=root;
        for(char c:prefix){
            if(node->children[c-'a']!=NULL){
                node=node->children[c-'a'];
            }
            else{
                return false;
            }
        }
       return true; 
        
    }
};


int main()
{
    Trie* obj = new Trie();
    obj->insert("hello");
    cout<<obj->search("hello");
    cout<<obj->startsWith("hell");
  
    return 0;
}
