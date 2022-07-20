#include <iostream>
using namespace std;

int recursion(int N, int M) {
	if (N % 3 == 1 && M % 3 == 1) //3X3기준 (1, 1) 지점에서 출력이 없어야 함
		return 1;
	else if (N / 3 && M / 3) { // 몫이 있다면 나눠서 더 작은 범위일 때 (1, 1) 지점 확인
		return recursion(N / 3, M / 3);
	}
	else //가장 작게 나누어도 (1, 1)인 부분이 없으면 * 출력
		return 0;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			if (recursion(i, k))
				cout << ' ';
			else
				cout << '*';
		}
		cout << '\n';
	}
	return 0;
}
