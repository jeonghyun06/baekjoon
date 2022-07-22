#include <iostream>
using namespace std;

int main() {
	int T, N, M;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		unsigned long long int num = 1, den = 1; 	// 최대 29!/15!의 연산을 하므로 큰 수를 다루는 정수형
		if(N>M-N) 					// 수가 너무 커지지 않도록 조합의 성질 이용(nCm==nCn-m)
			N=M-N;
		for (int i = 0; i < N; i++) {
			num = num * (M - i); //M!/(M-N)!
			den = den * (i + 1); //N!
		}
		cout << num / den << '\n';
	}

	return 0;
}
