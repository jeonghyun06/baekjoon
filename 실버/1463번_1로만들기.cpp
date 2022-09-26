#include <iostream>
using namespace std;

int cnt[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, mi;
	cin >> N;
	cnt[1] = 0;
	cnt[2] = 1;
	for (int i = 3; i <= N;i++) {
		mi = cnt[i-1];
		if (!(i % 3))
			mi = min(cnt[i / 3], mi);
		if (!(i % 2)) //질문 : 2로 나누는게 더 효율적인 경우가 있음 -> else if문에서 if문으로 변경
			mi = min(mi, cnt[i / 2]);
		cnt[i] = 1 + mi;
	}
	cout << cnt[N];
}
