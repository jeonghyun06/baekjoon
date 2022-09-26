#include <iostream>
using namespace std;

enum color{RED, GREEN, BLUE};
int sum[3][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, r, g, b;
	cin >> n;
	cin >> sum[RED][0] >> sum[GREEN][0] >> sum[BLUE][0];

	for (int i = 1; i < n; i++) {
		cin >> r >> g >> b;
		sum[RED][i] = r + min(sum[GREEN][i - 1], sum[BLUE][i - 1]);
		sum[GREEN][i] = g + min(sum[RED][i - 1], sum[BLUE][i - 1]);
		sum[BLUE][i] = b + min(sum[GREEN][i - 1], sum[RED][i - 1]);
	}
	int result = min(sum[RED][n - 1], sum[GREEN][n - 1]);
	result = min(result, sum[BLUE][n - 1]);
	cout << result;
}
