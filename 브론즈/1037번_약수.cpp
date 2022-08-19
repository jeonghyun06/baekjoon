#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int* num = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num, num + N);
	cout << num[0] * num[N - 1];
	return 0;
}
