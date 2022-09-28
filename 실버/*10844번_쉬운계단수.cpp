#include <iostream>
using namespace std;

int dp[101][10];  //dp[자리수][끝나는 숫자]

int dynamicProgramming(int n) {
	dp[1][0] =0;
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1];
		for (int j = 1; j < 9; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
		dp[i][9] = dp[i - 1][8];
	}
	int sum2 = 0;
	for (int i = 0; i <= 9; i++)
		sum2 = (sum2 + dp[n][i]) % 1000000000;
	return sum2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	cout<<dynamicProgramming(N);
}
