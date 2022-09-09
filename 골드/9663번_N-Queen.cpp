#include <iostream>
using namespace std;

int N;
int cnt = 0;
bool isusedC[14]{ false, };
bool isusedR[14]{ false, };
bool sum[28];
bool diff[29];

void NQueen(int qcnt, int col) {
	if (qcnt == N) {
		cnt++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!(isusedC[col] || isusedR[i] || sum[i + col] || diff[i - col + 14])) {
			isusedC[col] = true;
			isusedR[i] = true;
			sum[i + col] = true;
			diff[i - col + 14] = true;
			NQueen(qcnt + 1, col+1, i);
			isusedC[col] = false;
			isusedR[i] = false;
			sum[i + col] = false;
			diff[i - col + 14] = false;
		}
	}

	/*for (int i = 0; i < N; i++) {                                        //맨 처음 작성한 코드로 왜 틀렸는지 몰라 한참을 헤맸다. 
		for (int j = 0; j < N; j++) {                                        //문제는 같은 경우를 다시 센다는 점이었는데 그 이유는 매번 0부터 시작하기 때문!
			if (!(isusedC[i] || isusedR[j] || sum[i + j] || diff[i-j+14])) {   //->그래서 어차피 모든 열에 하나의 퀸이 있으므로 그를 세는 매개변수를 하나 놓고 증가시키면서 세도록 했다. 그 결과 성공!
				col.push_back(i);
				row.push_back(j);
				isusedC[i] = true;
				isusedR[j] = true;
				sum[i + j] = true;
				diff[i-j+14] = true;
				cout << qcnt << ' ' << i << ' ' << j << '\n';
				NQueen(qcnt + 1,i,j);
				col.pop_back();
				row.pop_back();
				isusedC[i] = false;
				isusedR[j] = false;
				sum[i + j] = false;
				diff[i-j+14] = false;
			}
		}
	}*/
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	NQueen(0, 0);
	cout << cnt;
	return 0;
}
