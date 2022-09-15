#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int* cnt = new int[n] {0, };  //n까지의 합 중 가장 큰 값 찾기
	cin >> cnt[0];
	int ma = cnt[0];
	for (int i = 1; i < n; i++) {
		cin >> cnt[i];
		cnt[i] = max(cnt[i] + cnt[i - 1], cnt[i]);
		ma = max(cnt[i], ma);
	}
	
	cout << ma;
}
