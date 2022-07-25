#include <iostream>
#include <string>
using namespace std;

int count(string* che) {                      //몇 개의 체스판을 다시 칠할지 확인하는 함수
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 4; k++) {
			if (che[2 * i][2 * k] == 'W')
				cnt++;
			if (che[2 * i + 1][2 * k + 1] == 'W')
				cnt++;
			if (che[2 * i][2 * k + 1] == 'B')
				cnt++;
			if (che[2 * i + 1][2 * k] == 'B')
				cnt++;
		}
	}

	return cnt > 64 - cnt ? 64 - cnt : cnt;   //백으로 시작할 때와 흑으로 시작할 때 중 더 작은 횟수 return
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int N, M, cnt;
	cin >> N >> M;
	string* chess = new string[N];          //전체 보드 저장
	string chessTmp[8];                     //체스판 크기(8X8) 보드 저장
	for (int i = 0; i < N; i++) {
		cin >> chess[i];
	}
	int min = 32;                           //전체가 백 또는 흑일 때 최대 32개의 칸을 바꿔야 한다.
	for (int i = 0; i <= N - 8; i++) {
		for (int k = 0; k <= M - 8; k++) {
			for (int n = 0; n < 8; n++) {       //체스판 추출 - i~i+7번째 체스판
				chessTmp[n] = chess[i + n].substr(k, k + 8);  //8개의 열 선택
			}
			cnt = count(chessTmp);
			min = min > cnt ? cnt : min;        //각 경우 최소 횟수 저장
		}
	}
	cout << min;
	return 0;
}
