/******************************************************************************

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

void backtrack(const vector<pair<int,int>>& unique_items,
               int index,       // index of the item to consider
               int& min_num,    // size of global result
               int& cur_sum,    // sum of all items in cur_result
               int& max_sum,    // sum of global result
               int limit,       // sum threshold, always sum/2+1
               vector<int>& cur_result, // current list
               vector<int>& output)     // global list
{
    if (cur_sum >= limit) {
        if (cur_result.size() < min_num) {
            min_num = cur_result.size();
            max_sum = cur_sum;
            output = cur_result;
        } else if (cur_result.size() == min_num && cur_sum > max_sum) {
            // the subset A we found has the same size with the global
            // update it to maxmize the total weight
            max_sum = cur_sum;
            output = cur_result;
        }
        return;
    }

    for (int i = index; i < unique_items.size(); ++i) {
        // add current element
        vector<int> new_items(unique_items[i].second,
                              unique_items[i].first);
        cur_result.insert(cur_result.end(),
                          new_items.begin(),
                          new_items.end());
        cur_sum += unique_items[i].first * unique_items[i].second;

        backtrack(unique_items, i+1, min_num, cur_sum, max_sum, limit,
                  cur_result, output);
        
        // restore cur_result
        cur_result.resize(cur_result.size() - unique_items[i].second);
        cur_sum -= unique_items[i].first * unique_items[i].second;
    }
}

void optimslBoxWeight(vector<int>& input,
                      vector<int>& output) {
    int sum = 0;
    map<int, int> freq_map;
    for (int i : input) {
        freq_map[i]++;
        sum += i;
    }
    
    vector<pair<int,int>> unique_items;
    for (auto p : freq_map) {
        unique_items.push_back(make_pair(p.first, p.second));
    }
    
    sort(unique_items.begin(), unique_items.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second < b.second;
    });
    
    int min_num = INT_MAX;
    int cur_sum = 0;
    int max_sum = 0;
    vector<int> cur_reuslt;
    backtrack(unique_items, 0, min_num, cur_sum, max_sum, sum/2+1, cur_reuslt, output);
    // for(int i = 0; i < output.size(); i++)
    //     cout << output[i] << ' ';
    // cout << endl;
    sort(output.begin(), output.end());
}

int main() {
    std::cout << "Start testing!\n";
    vector<vector<int>> input =
    {
        {1, 2, 5, 8, 4},
        {5, 3, 2, 4, 1, 2},
        {4, 9, 7, 3, 9, 8},
        {20, 15, 15, 50, 20},
        {20, 15, 20, 50, 20},
        {10, 9, 9, 6, 5, 4, 3, 2, 1},
        {10, 4, 4, 4, 3},
        {2, 1, 1, 1},
        {20, 10, 1, 1}
    };
    
    vector<vector<int>> expected =
    {
        {5, 8},
        {4, 5},
        {8, 9, 9},
        {20, 20, 50},
        {15, 50},
        {9, 9, 10},
        {3, 10},
        {1, 1, 1},
        {20}
    };
    
    for (int i = 0; i < input.size(); ++i) {
        vector<int> output;
        // cout << "test " << i << endl;
        optimslBoxWeight(input[i], output);
        assert(output == expected[i]);
    }
    cout << "all tests passed\n";
}
