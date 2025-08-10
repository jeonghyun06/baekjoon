#include <iostream>
using namespace std;

int n, gcd;
int tree[100000];

int GCD(int a, int b) {
	int r = a % b;
	if (r == 0) return b;
	return GCD(b, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	cin >> tree[0] >> tree[1];
	gcd = tree[1] - tree[0];
	for (int i = 2; i < n; i++) {
		// 차의 최대공약수
		cin >> tree[i];
		gcd = GCD(gcd, tree[i] - tree[i-1]);
	}

	cout << (tree[n - 1] - tree[0]) / gcd - n + 1;
	return 0;
}