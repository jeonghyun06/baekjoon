#include <iostream>
using namespace std;

int GCD(int a, int b) {
	int r;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	int a, b;
	while (T--) {
		cin >> a >> b;
		int gcd = GCD(a, b);
		int cmd = a * b / gcd;
		cout << cmd << '\n';
	}
}
