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
	sort(cards, cards + N); //이진탐색은 무조건 정렬되어있어야함.
	cin >> M;
	int number;
	for (int i = 0; i < M; i++) {
		cin >> number;
		if (binary_search(cards, cards + N, number)) //맨 처음 find로 했다가 시간초과-> 빠른 탐색기법인 이진탐색이용
			cout << "1 ";
		else
			cout << "0 ";
	}

	return 0;
}
