#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N;
	int* cards = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> cards[i];
	}
	sort(cards, cards + N);
	cin >> M;
	int a;
	int* cnt = new int[M] {0, };
	for (int i = 0; i < M;i++) {
		cin >> a;
		cnt[i] = upper_bound(cards, cards + N, a) - lower_bound(cards,cards+N,a);
	}

	for (int i = 0; i < M; i++) {
		cout << cnt[i] <<' ';
	}

	return 0;
}
