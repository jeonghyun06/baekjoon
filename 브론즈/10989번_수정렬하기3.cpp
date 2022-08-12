#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int counts[10001]{ 0, };
	int cnt;
	for (int i = 0; i < N; i++) {
		cin >> cnt;
		counts[cnt]++;
	}
	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < counts[i]; j++)
			cout << i << '\n';
	}
	return 0;
}
