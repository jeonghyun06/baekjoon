#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	int* sum = new int[n + 1]{ 0, };
	for (int i = 1; i <= n; i++) {
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}
	int m = -10000000;  //최솟값 체크
	for (int i = 0; i <= n - k; i++) {  //범위 체크
		m = max(sum[i + k] - sum[i], m);
	}
	cout << m;
	return 0;
}
