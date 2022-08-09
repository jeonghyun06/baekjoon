#include <iostream>
using namespace std;

int GCD(int a, int b) {     //유클리드 호제법을 이용한 최대공약수 구하기
	int R = a % b;
	while (R != 0) {
		a = b;
		b = R;
		R = a % b;
	}
	return b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, R, r, gcd;
	cin >> N;
	cin >> R;
	N--;
	while (N--) {
		cin >> r;
		gcd = GCD(R, r);
		cout << R / gcd << '/' << r / gcd << '\n';
	}
	return 0;
}
