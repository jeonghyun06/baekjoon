#include <iostream>
using namespace std;

void quadTree(string* quad, int n, int startc, int startl) {
	if (n == 1) {                  	              //n==1이면 더이상 쪼개지 않고 현재 상황을 출력
		cout << quad[startc][startl];
		cout << quad[startc][startl + 1];
		cout << quad[startc + 1][startl];
		cout << quad[startc + 1][startl + 1];
		return;
	}
	else {
		bool one = true;
		bool zero = true;
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < n; k++) {
				if (quad[startc + i][startl + k]-48)		//1 이 그 위치에 있으면 zero는 flase
					zero = false;
				else one = false;							          //0이 그 위치에 있으면 one은 false
				if (!(zero || one)) break;				      //zero도 one도 아닌 경우 탐색 중단.
			}
			if (!(zero || one)) break;
		}
		if (zero || one) {	//모두 zero 또는 one이면 해당 값 출력
			cout << one;
			return;
		}
		cout << '(';
		quadTree(quad, n / 2, startc, startl);	    //왼쪽 위
		if (n / 2 != 1) {	                           //n을 쪼갰을 때 더이상 쪼갤 수 없다면 한 번만 실행
			quadTree(quad, n / 2, startc, startl + n / 2);	//오른쪽 위
			quadTree(quad, n / 2, startc + n / 2, startl);	//왼쪽 아래
			quadTree(quad, n / 2, startc + n / 2, startl + n / 2);	//오른쪽 아래
		}
		cout << ')';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	string* q = new string[n];
	for (int i = 0; i < n; i++) {
		cin >> q[i];
	}
	
	if (n==1)	                        //n이 1이면 모든 값이 이미 같으므로 입력받은 값 출력
		cout << q[0][0];
	else quadTree(q, n, 0, 0);

	return 0;
}
