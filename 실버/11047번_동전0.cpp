#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;
	int* A = new int[N];
	for (int i = 0; i < N; i++)
		cin >> A[i];

	int cnt = 0;
	for (int i = N - 1; K != 0; i--) {
		if (A[i] <= K) {
			cnt += K / A[i];
			K -= (K / A[i]) * A[i];
		}
	}
	cout << cnt;
	return 0;
}
