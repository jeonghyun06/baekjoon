#include <iostream>
#include <vector>
using namespace std;

bool visited[8] = { false, };

//비어있는 수열에 하나씩 값을 추가하여 크기가 만족되면 출력하는 방식
//*상태분간트리
//되돌아가기위해 마지막 원소를 빼고 다시 되돌아감
//백트래킹의 전형적 구조
//재귀적으로 구현되므로 based condition이 필요

void backtracking(vector<int> num, int n, int m, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < num.size(); i++) {
			cout << num[i]<<' ';
		}
		cout << '\n';
		return;
	}
	//핵심파트
	for (int i = 0; i < n; i++) {		//1~n 중 아직 쓰이지 않은 수를 찾아냄
		if (!visited[i]) {
			visited[i] = true;
			num.push_back(i + 1);
			backtracking(num, n, m, cnt + 1);
			num.pop_back();				
			visited[i] = false;			//사용이 끝난 부분은 다시 제거
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> num;
	backtracking(num, N, M, 0);

	return 0;
}
