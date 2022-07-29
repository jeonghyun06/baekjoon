#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	int T, x1, y1, r1, x2, y2, r2;
	int distance, sum, difference;
	cin >> T;
	while (T--) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		distance = pow(x1 - x2, 2) + pow(y1 - y2, 2);       //두 원의 중심 사이 거리 제곱
		sum = pow(r1 + r2, 2);                              //두 반지름의 합 제곱
		difference = pow(r1 - r2, 2);                       //두 반지름의 차 제곱
    
		if (distance == 0 && difference == 0)               //두 원이 일치할 때
			cout << -1 << '\n';
		else if (sum < distance or difference > distance)   //두 원의 교점이 없을 때 -> 한 원이 다른 원 포함 또는 둘 사이의 거리가 반지름의 합보다 클 때
			cout << 0 << '\n';
		else if (sum == distance or difference == distance) //두 원이 접할 때 -> 두 중심 사이의 거리가 반지름 합과 같으면 외접, 반지름 차와 같으면 내접
			cout << 1 << '\n';
		else                                                //두 원의 교점이 2개 있을 때
			cout << 2 << '\n';
	}

	return 0;
}
