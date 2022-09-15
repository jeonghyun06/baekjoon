#include <iostream>
using namespace std;

int f[41];
int cnt1, cnt2;

int fib(int n) {
	if (n == 1 || n == 2) {
		cnt1++;
		return 1;
	}
	else
		return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n) {
	f[1] = f[2] = 1;
	for (int i = 3; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
		cnt2++;
	}
	return f[n];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	fib(n);
	fibonacci(n);
	cout << cnt1 <<' '<< cnt2;
}
