class Solution {
    vector<vector<int>>result;
    vector<int>candidates;
    int target;
    /*
    Backtracking as DFS(n ary tree)Time Complexity: O(N^(T/M)+1)number of steps= total nodes.
    at each node- constant time to process ,
    leaf nodes - linear time to make copy of combination.
    Space- O(target/minimal value of number) - to store combination.
    as well as to keep adding smallest number till we reach target.
 )
    
    
    */
    void backtrack(int remaining_sum, vector<int>temp, int start){
        if(remaining_sum==0){
            result.push_back(temp);
        }
        if(remaining_sum<0)
            return;
        
        for(int i=start;i<candidates.size();i++){
            // add the number to combination
            temp.push_back(candidates[i]);
            // start from current number - repeatition is allowed for same number
            backtrack(remaining_sum-candidates[i] , temp, i);
            // remove the number to backtrack
            temp.pop_back();
        }
        
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->candidates=candidates;
        this->target=target;
        vector<int>temp;
        backtrack(target,temp, 0);
        
       return result; 
        
    }
};
