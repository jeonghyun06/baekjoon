#include <iostream>
#include <algorithm>
using namespace std;

int sum[502][502];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	cin >> sum[1][1];
	int ma = sum[1][1]; //입력이 한 개일 때를 고려하지 않아 틀림.
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> sum[i][j];
			sum[i][j] += max(sum[i - 1][j - 1], sum[i - 1][j]);
			ma = ma > sum[i][j] ? ma : sum[i][j];
		}
	}
	cout << ma;
}
