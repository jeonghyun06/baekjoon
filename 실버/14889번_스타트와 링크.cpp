#include <iostream>
#include <vector>
using namespace std;

int N;
int** power;
bool* check;         //start 팀만 확인
vector<int> start;    
vector<int> rink;
int minimum = 100000000;

void backtracking(int cnt) {
	if (cnt==N/2) {
		for (int i = 0; i < N; i++)
			if (!check[i])                //start팀이 아니면 rink 팀에 넣음.
				rink.push_back(i);
		int stsum = 0;
		int rksum = 0;
		for (int i = 0; i < N/2; i++) { //합 계산
			for (int j = i; j < N/2; j++) {
				stsum += power[start[i]][start[j]];
				stsum += power[start[j]][start[i]];
				rksum += power[rink[j]][rink[i]];
				rksum += power[rink[i]][rink[j]];
			}
		}
		minimum = min(minimum, abs(stsum - rksum)); //가장 작은 차 구하기
		rink.clear();   //새로운 rink 팀을 구성하기 위해 현재 rink 모두 없앰
		return;
	}
	for (int i = start[cnt-1]; i < N; i++) {    //순차적으로 증가하는 경우만 세주어 중복을 피했다.
		if (!check[i]) {
			check[i] = true;
			start.push_back(i);
			backtracking(cnt+1);
			check[i] = false;
			start.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	power = new int* [N];
	for (int i = 0; i < N; i++)
		power[i] = new int[N];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> power[i][j];
	}
	check = new bool[N] {false, };
	check[0] = true;    //0번 선수는 무조건 들어있다고 가정. <-어떤 팀이건 무조건 들어가기 때문에
	start.push_back(0);
	backtracking(1);    //start팀이 1명 채워진 상태로 시작하므로 cnt == 1

	cout << minimum;

	return 0;
}
