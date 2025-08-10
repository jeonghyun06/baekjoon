#include <iostream>
using namespace std;

long long int a, b;

long long int GCD(long long s, long long l) {
	long long r = s % l;
	if (r == 0) return l;
	return GCD(l, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b;
	long long gcd = GCD(a, b);
	cout << a * b / gcd;
	
	return 0;
}