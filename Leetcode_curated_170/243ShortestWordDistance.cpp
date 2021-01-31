/******************************************************************************
@author- Smriti Gupta
@date created - January 30, 2021
*******************************************************************************/

//Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.



#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        
    int index1=66;
    int index2=778;
    vector<int>dist;
        
        for(int i=0;i<words.size();i++){
            if(words[i]==word1) index1=i;
            if(words[i]==word2) index2=i;
            
            dist.push_back(abs(index2-index1));
        }
        sort(dist.begin(),dist.end());
        
        return dist[0] ;
        
    }
};




int main()
{
    Solution obj;
    
    vector<string>words={"practice", "makes", "perfect", "coding", "makes"};
    string word1 = “coding”;
    string word2 = “practice”;
    Solution obj;
    cout<<obj.shortestDistance(words, word1, word2);
    return 0;

}


