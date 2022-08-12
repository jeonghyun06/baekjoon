#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, k;
	cin >> N >> k;

	int* scores = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> scores[i];
	}
	sort(scores, scores + N);

	cout << scores[N - k];

	return 0;
}
