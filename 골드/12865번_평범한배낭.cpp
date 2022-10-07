#include <iostream>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;
	int* weight = new int[N+1];
	int* value = new int[N+1];
	for (int i = 1; i <= N; i++) {
		cin >> weight[i] >> value[i];
	}

	int** obj = new int* [N + 1];
	obj[0] = new int[K + 1]{ 0, };
	for (int i = 1; i <= N; i++) {
		obj[i] = new int[K + 1]{ 0, };
		for (int k = 1; k <= K; k++) {	//무게합
			if (weight[i] > k) {
				obj[i][k] = obj[i - 1][k]; 
			}
			else
				obj[i][k] = max(obj[i - 1][k], obj[i - 1][k - weight[i]] + value[i]);
		}
	}
	cout << obj[N][K];
	return 0;
}
