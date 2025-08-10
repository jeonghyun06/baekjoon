#include <iostream>
using namespace std;

long long int a1, b1, a2, b2;

long long int GCD(long long a, long long b) {
	long long r = a % b;
	if (r == 0) return b;
	return GCD(b, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> a1 >> b1;
	cin >> a2 >> b2;

	long long son = a1 * b2 + a2 * b1;
	long long mom = b1 * b2;

	long long gcd = GCD(son, mom);

	cout << son / gcd << ' ' << mom / gcd;

	return 0;
}