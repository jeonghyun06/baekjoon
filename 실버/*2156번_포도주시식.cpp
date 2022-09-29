#include <iostream>
using namespace std;

int wine[10001];
int sum[3][10001];

int m(int o, int t, int th) {
	o = max(o, t);
	th = max(o, th);
	return th;
}
int DP(int n) {
	sum[1][0] = sum[2][0] = wine[0];
	for (int i = 1; i < n; i++) {
		sum[0][i] += m(sum[0][i - 1], sum[1][i - 1], sum[2][i - 1]);	//현재 연속되지 않음. -> 이전 차례는 놓지 않음.
		sum[1][i] += sum[0][i - 1] + wine[i];	//현재 1개 연속
		sum[2][i] += sum[1][i - 1] + wine[i]; //현재 2개 연속 -> 다음차례에는 놓을 수 없음.
	}
	return m(sum[0][n - 1], sum[1][n - 1], sum[2][n - 1]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> wine[i];
	}
	int result;
	if (N < 3)
		result = wine[0] + wine[1];
	else
		result = DP(N);

	cout << result;

}
