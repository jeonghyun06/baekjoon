#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n, x1, y1, x2, y2, cx, cy, cr;
	int cnt;;
	cin >> T;
	while (T--) {
		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;
		cnt = 0;
		for (int i = 0; i < n; i++) {
			cin >> cx >> cy >> cr;
			if ((pow(x1 - cx, 2) + pow(y1 - cy, 2)) < pow(cr, 2)) {       //출발점과 도착점을 각각 감싸는 원 찾기
				if ((pow(x2 - cx, 2) + pow(y2 - cy, 2)) > pow(cr, 2))       //두 지점을 모두 감싸는 원 제외
					cnt++;
			}
			else if ((pow(x2 - cx, 2) + pow(y2 - cy, 2)) < pow(cr, 2))
				cnt++;
		}
		cout << cnt << '\n';
		
	}

	return 0;
}
