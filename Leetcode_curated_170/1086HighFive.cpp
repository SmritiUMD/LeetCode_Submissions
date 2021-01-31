/******************************************************************************
@author -Smriti Gupta
@date created-January 30,2021
*******************************************************************************/

//Given a list of the scores of different students, items, where items[i] = [IDi, scorei]
//represents one score from a student with IDi, calculate each student's top five average.



#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int,priority_queue<int>>scores;
        map<int,priority_queue<int>>::iterator it;
        for(auto item:items){
            int id=item[0];
            int score=item[1];
            scores[id].push(score);
        }
        vector<vector<int>>solution;
        for(it=scores.begin();it!=scores.end();it++){
            int sum=0;
            for(int i=0;i<5;i++){
                sum+=it->second.top();
                it->second.pop();
            }
            solution.push_back({it->first,sum/5});
        }
       return solution; 
    }
    
    void printSolution(vector<vector<int>>solution){
      for(auto i:solution){
      cout<<i[0]<<"-"<<i[1]<<endl;
    }
    }
};




int main()
{
    Solution obj;
    vector<vector<int>>scores={{1,91},{1,92},{2,93},{2,97},{1,60},{2,77},{1,65},{1,87},{1,100},{2,100},{2,76}};
    obj.printSolution(obj.highFive(scores));
    return 0;

}


