#include <iostream>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	int** numbers = new int* [N + 1];
	numbers[0] = new int[N + 1]{ 0, };
	for (int i = 1; i <= N; i++) {
		numbers[i] = new int[N + 1]{ 0, };
		for (int j = 1; j <= N; j++) {
			cin >> numbers[i][j];
			numbers[i][j] += numbers[i - 1][j];
		}
	}
	int sum = 0;
	int x1, y1, x2, y2;
	for (int i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int k = y1; k <= y2; k++) {  //이부분에서 애먹음
			sum += numbers[x2][k] - numbers[x1 - 1][k];
		}
		cout << sum<<'\n';
		sum = 0;
	}
	

	return 0;
}
