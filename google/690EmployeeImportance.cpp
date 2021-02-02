/******************************************************************************
@author - Smriti Gupta
@date created - Feb 2,21

*******************************************************************************/
/**You are given a data structure of employee information, which includes the employee's unique id, 
their importance value and their direct subordinates' id.

For example, employee 1 is the leader of employee 2, and employee 2 is the leader of employee 3.
They have importance value 15, 10 and 5, respectively. Then employee 1 has a data structure like [1, 15, [2]], 
and employee 2 has [2, 10, [3]], and employee 3 has [3, 5, []]. Note that although employee 3 is also a subordinate 
of employee 1, the relationship is not direct.
**/

#include <bits/stdc++.h>

using namespace std;

// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
    Employee(int id, int imp, vector<int>sub){
        this->id=id;
        this->importance=imp;
        vector<int>subordinates = sub;
        
    }
};


class Solution {
    map<int,Employee*> dir;
    
    private:
        int dfs(int eid){
           Employee* employee=dir[eid];
            int ans=employee->importance;
            for(int sub_id: employee->subordinates)
                ans+=dfs(sub_id);
            
            return ans;
        }
public:
    int getImportance(vector<Employee*> employees, int id) {
        for(Employee* e:employees)
            dir.insert({e->id, e});
            return dfs(id);
        
        
    }
};

int main()
{
    Employee* emp1 = new Employee(1, 5, {2, 3});
    Employee* emp2 = new Employee( 2, 3, {});
    Employee* emp3 = new Employee(3, 3, {});
    vector<Employee*> employees = {emp1, emp2, emp3};
    int id;
    
    Solution obj;
    obj.getImportance(employees , id );

    return 0;
}
