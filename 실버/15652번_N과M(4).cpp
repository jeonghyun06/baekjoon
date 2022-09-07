#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> num;

void backtracking(int cnt){
	if(cnt>1 && num[cnt-2]>num[cnt-1]){
		return;
	}
	if(cnt==M){
		for(int i=0;i<M;i++){
			cout<<num[i]<<' ';
		}
		cout<<'\n';
		return;
	}
	for(int i=0;i<N;i++){
		num.push_back(i+1);
		backtracking(cnt+1);
		num.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0);
	
	cin>>N>>M;
	backtracking(0);
	
	return 0;
}

