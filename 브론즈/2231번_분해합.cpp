#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, tmp, cnt;
	int answer = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cnt = i;
		tmp = i;
		while (tmp) {                 //각 자리수 합 구하기
			cnt += tmp % 10;
			tmp = tmp / 10;
		}
		if (N == cnt) {
			answer = i;
			break;
		}
	}
	cout << answer;
	return 0;
}
