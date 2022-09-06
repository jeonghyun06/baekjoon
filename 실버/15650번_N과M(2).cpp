#include <iostream>
#include <vector>
using namespace std;

bool visited[8] = { false, };
int N;
int M;
vector<int> num;
void backtracking(int cnt) {
	if (cnt > 1 && num[cnt - 2] > num[cnt-1])
		return;
	if (cnt == M) {
		for (int i = 0; i < num.size(); i++) {
			cout << num[i]<<' ';
		}
		cout << '\n';
		return;
	}
	
	for (int i = 0; i < N; i++) {		
		if (!visited[i]) {
			visited[i] = true;
			num.push_back(i + 1);
			backtracking(cnt + 1);
			num.pop_back();				
			visited[i] = false;			
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	backtracking(0);

	return 0;
}
