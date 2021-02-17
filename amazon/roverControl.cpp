/******************************************************************************
@author - Smriti GUpta
@date created = Feb 17,21

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;
int finalPos(vector<string>commands, int n){
    
    vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
    int x=0;
    int y=0;
    int new_x=0;
    int new_y=0;
    for(int i=0;i<commands.size();i++){
        if(commands[i]=="RIGHT"){
            new_x=0;
            new_y=1;
        }
        else if(commands[i]=="LEFT"){
            new_x=0;
            new_y=-1;
        }
        else if(commands[i]=="UP"){
            new_x=-1;
            new_y=0;
        }
        else if(commands[i]=="DOWN"){
            new_x=1;
            new_y=0;
        }
        
        if(y+new_y>=0 && y+new_y<n-1 && x+new_x>=0 && x+new_x<n-1){
            cout<<new_x<<new_y<<endl;
            x+=new_x;
            y+=new_y;
        }
        else{
            continue;
        }
        
    }
    // cout<<x<<y;
    return (x*n)+y;
            
       
    }




int main()
{
    
   vector<string>commands ={"RIGHT", "DOWN", "LEFT", "LEFT", "DOWN"} ;
   int n=4;
   cout<<finalPos(commands, n);
    return 0;
}

