#include <iostream>
using namespace std;

int N;
int op[4];
int result;
int maximum = -100000000;
int minimum = 100000000;
int* num;

void operation(int cnt) {
	if (cnt == N) {
		maximum = max(maximum, result);
		minimum = min(minimum, result);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i]) {
			op[i]--;
			int tmp = result;
			switch (i) {
			case 0:
				result += num[cnt];
				break;
			case 1:
				result -= num[cnt];
				break;
			case 2:
				result *= num[cnt];
				break;
			case 3:
				result /= num[cnt];
				break;
			}
			operation(cnt + 1);
			op[i]++;
			result = tmp;
		}
	}
}

int main() {
	cin >> N;
	num = new int[N];
	for (int i = 0; i < N; i++)
		cin >> num[i];
	for (int i = 0; i < 4; i++)
		cin >> op[i];

	result = num[0];
	operation(1);
	cout << maximum << '\n' << minimum;
	return 0;
}
