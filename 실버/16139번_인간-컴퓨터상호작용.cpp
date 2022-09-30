#include <iostream>
using namespace std;

int cnt[200001][26];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int q, l, r;
	char a;
	string S;

	cin >> S >> q;
	cnt[0][S[0] - 97] = 1;
	for (int i = 1; i < S.length(); i++) {
		for (int j = 0; j < 26; j++)
			cnt[i][j] = cnt[i - 1][j];
		cnt[i][S[i]-97]++;
	}
	for (int i = 0; i < q; i++) {
		cin >> a >> l >> r;
		if (l == 0)   //l이 0일때 예외처리를 해주지 않아 틀림.
			cout << cnt[r][a - 97] << '\n';
		else {
			r = cnt[r][a - 97];
			l = cnt[l - 1][a - 97];
			cout << r - l << '\n';
		}
	}

	return 0;
}
