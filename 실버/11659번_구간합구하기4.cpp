#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, a, b;
	cin >> n >> m;

	int* sum = new int[n + 1]{ 0, };
	for (int i = 1; i <= n; i++) {
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}
	
	while (m--) {
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << '\n';  //누적합 알고리즘 : 시작점부터의 모든 누적합을 구해 특정 구간의 값을 뺌으로써 구간 합을 구하는 방법
	}

	return 0;
}
