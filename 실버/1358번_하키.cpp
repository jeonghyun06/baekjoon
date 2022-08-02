#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int W, H, X, Y, P;
	cin >> W >> H >> X >> Y >> P;
	int x, y;
	int cnt = 0;
	while (P--) {
		cin >> x >> y;
		if (x >= X && x <= (X + W) && y >= Y && y <= (Y + H))                     //중앙에 위치한 선수
			cnt++;
		else if (pow(x - X, 2) + pow(y - Y - H / 2, 2) <= pow(H / 2, 2)           //왼쪽 반원에 위치한 선수
             || pow(x - X - W, 2) + pow(y - Y - H / 2, 2) <= pow(H / 2, 2))   //오른쪽 반원에 위치한 선수
			cnt++;
	}
	cout << cnt;
	return 0;
}
