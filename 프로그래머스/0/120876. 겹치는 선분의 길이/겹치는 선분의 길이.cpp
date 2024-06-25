#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    int arr[201]{};
    for(int i=0;i<lines.size();i++){
        arr[lines[i][0] + 100]++;
        arr[lines[i][1] + 100]--;
    }
    
    for(int i=0;i<=200;i++){
        arr[i + 1]+=arr[i];
        cout<<arr[i]<<' ';
        if(arr[i]>1) answer++;
    }
    
    return answer;
}