#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool compare(pair<int, int> line1, vector<vector<int>> dots){
    pair<int, int> line2={-1,-1};
    for(int i=0;i<4;i++){
        if(line1.first != i && line1.second != i){
            if(line2.first==-1) line2.first = i;
            else line2.second = i;
        }
    }
    
    float line1Scope = (float)(dots[line1.first][0]-dots[line1.second][0])/(dots[line1.first][1]-dots[line1.second][1]);
    float line2Scope = (float)(dots[line2.first][0]-dots[line2.second][0])/(dots[line2.first][1]-dots[line2.second][1]);
    
    cout<<line1Scope<<' '<<line2Scope;
    return line1Scope == line2Scope;  
}

int solution(vector<vector<int>> dots) {
    for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            if(compare(make_pair(i, j), dots)){
                return 1;
            }
        }
    }
    return 0;
}