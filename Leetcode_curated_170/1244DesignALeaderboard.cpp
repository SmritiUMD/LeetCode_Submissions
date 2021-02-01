/******************************************************************************
@author- Smriti Gupta
@date created- February 1,21
*******************************************************************************/
/**
Design a Leaderboard class, which has 3 functions:

addScore(playerId, score): Update the leaderboard by adding score to the given player's score. If there is no player with such id in the leaderboard, add him to the leaderboard with the given score.
top(K): Return the score sum of the top K players.
reset(playerId): Reset the score of the player with the given id to 0 (in other words erase it from the leaderboard). It is guaranteed that the player was added to the leaderboard before calling this function.
Initially, the leaderboard is empty.
**/

#include <bits/stdc++.h>

using namespace std;

class Leaderboard {
    private:
    map<int,int>scores;
    
public:
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        if(scores.find(playerId)!=scores.end()){
            scores[playerId]+=score;
        }
        scores.insert({playerId,score});
        
    }
    
    int top(int K) {
    //using priority queue to get top scores
        priority_queue<int>q;
        map<int,int>::iterator it;
        for(it=scores.begin();it!=scores.end();it++){
            q.push(it->second);
        }
        int counter=0;
        int sum=0;
        while(counter<K){
            sum+=q.top();
            q.pop();
            counter++;
        }
        return sum;
        
    }
    
    void reset(int playerId) {
        scores[playerId]=0;
        
    }
};



int main(){
    
 Leaderboard obj;
 obj.addScore(1,73);
 obj.addScore(2,56);
 obj.addScore(3,39);
 obj.addScore(4,51);
 obj.addScore(5,4);
cout<<"sum of top 1"<<"-"<< obj.top(1)<<endl;
 obj.reset(1);
 obj.reset(2);
 obj.addScore(2,51);
 cout<<"sum of top 3"<<"-"<< obj.top(3)<<endl;

 return 0;
 
}

 

