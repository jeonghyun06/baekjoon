#include <iostream>
using namespace std;

long long int p[101]; //범위를 잘못 설정해주어 틀렸음.

int padoban(int n) {
	p[1] = p[2] = p[3] = 1;
	p[4] = p[5] = 2;
	for (int i = 6; i <= n; i++) {
		p[i] = p[i - 5] + p[i - 1]; // 또는 p[i] = p[i-2]+p[i-3];
	}
	return p[n];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T, N;
	cin >> T;
	padoban(100);
	while (T--) {
		cin >> N;
		cout << p[N] << '\n';
	}

}
