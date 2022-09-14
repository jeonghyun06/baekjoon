#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;
	K = min(K, N - K);
	if (K == 0) { //K==0일때를 고려하지 않아 시간초과가 떴음.
		cout << 1;
		return 0;
	}
	int np = N--;
	int kp = K--;
	while (K) {
		np *= N--;
		kp *= K--;
	}
	cout << np / kp;
}
