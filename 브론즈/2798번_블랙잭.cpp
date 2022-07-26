#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
  
	int N, M;
	cin >> N >> M;
	int* card = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}
  
	int max = 0;
	for (int i = 0; i < N - 2; i++) {
		for (int k = i + 1; k < N - 1; k++) {
			for (int j = k + 1; j < N; j++) {     // 세 카드의 합이 M 이하이며 최대가 되는 경우 찾기 
				if (max < card[i] + card[k] + card[j] && card[i] + card[k] + card[j] <= M)
					max = card[i] + card[k] + card[j];
			}
		}
	}
	cout << max;
  
	return 0;
}
