/******************************************************************************
@author- Smriti Gupta
@date created - March 12, 21
*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Solution {
    /*
    This problem looks like graph- moving from current word - generating child nodes with one letter difference.
    Time Complexity: O(M^2×N), where M is the length of each word and N is the total number of words in the input word list.
    Iterating over length to find each word - O(M*N)
    forming each intermediate word - O(M).
    
    Space - For every word of M length, we need M^2 space to store its combination. For N words - O(M^2*N)
    queue in worst case - every word stored in it - O(M*N)
    */
    vector<string>neighbors(string str){
        vector<string>result;
        // making a opy of string to generate new arrangements
        string word=str;
        for(int i=0;i<str.size();i++){
            char temp=word[i];
            for(char c='a';c<='z';c++){
                word[i]=c;
                result.push_back(word);
            }
            // remove the changes on current index to start with next index
            word=str;
        }
        return result;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // using set for constant time look ups
        set<string>words;
        // queue for BFS - shortest transformation
        queue<string>q;
        for(int i=0;i<wordList.size();i++){
            words.insert(wordList[i]);
        }
        q.push(beginWord);
        words.erase(beginWord);
        int level=0;
        
        while(!q.empty()){
            // to keep a track of current level - single letter transformation
            int size=q.size();
            // increment the level for every transformation
            level++;
            for(int i=0;i<size;i++){
                string curr=q.front();
                q.pop();
                // termination condition
                if(curr==endWord)
                    return level;
                // find the neighbor of current element
                vector<string>neigh=neighbors(curr);
                for(auto x:neigh){
                    // if the neighbor is in the set then push into q and remove from set
                    if(words.find(x)!=words.end()){
                        words.erase(x);
                        q.push(x);
                    }
                }
            }
        }
//         if endWord is not found return 0;
        return 0;
        
    }
};
int main()
{
  
   string beginWord = "hit";
   string endWord = "cog";
   vector<string>wordList ={"hot","dot","dog","lot","log","cog"};
   
    Solution obj;
    
   cout<<obj.ladderLength(beginWord,endWord,wordList);
   
    return 0;
}
