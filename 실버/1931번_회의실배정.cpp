#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int* a,int* b) {
	if (a[1] == b[1])
		return a[0] < b[0];
	return a[1] < b[1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int** meeting = new int* [N];
	//n시에 도달하는 가장 cnt가 많은 것
	for (int i = 0; i < N; i++) {
		meeting[i] = new int[2];
		cin >> meeting[i][0] >> meeting[i][1];
	}
	sort(meeting, meeting + N, compare);
	int cnt = 0;
	int tmp = 0;
	for (int i = 0; i < N; i++) {
		if (meeting[i][0] >= tmp) {
			cnt++;
			tmp = meeting[i][1];
		}
	}
	cout << cnt;
	return 0;
}
