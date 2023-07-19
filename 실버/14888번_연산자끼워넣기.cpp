#include <iostream>
using namespace std;

int N;
int op[4];
int result;
int maximum = -1000000000;
int minimum = 1000000000;
int* num;

void operation(int cnt) {
	if (cnt == N) {		//연산자 개수만큼 연산을 한 경우 최대 혹은 최솟값인지 판단
		maximum = max(maximum, result);
		minimum = min(minimum, result);
		return;
	}
	for (int i = 0; i < 4; i++) {			//4개의 연산자 사용. -> 현재 상황에서 사용 가능한 연산자를 돌아가며 모두 사용해본다.
		if (op[i]) {				//쓸 수 있으면(개수가 0이 아니면) 다음 차례에 넣는다.
			op[i]--;			//사용했음 의미
			int tmp = result;		//여기까지의 연산 결과 저장
			switch (i) {			//어떤 연산자를 사용했는지에 따라 연산 진행
			case 0:
				result += num[cnt];
				break;
			case 1:
				result -= num[cnt];
				break;
			case 2:
				result *= num[cnt];
				break;
			case 3:
				result /= num[cnt];
				break;
			}				//각 연산자에 맞게 연산 후 이번 연산 결과 저장
			operation(cnt + 1);		//다음 차례에 오는 연산 수행

			op[i]++;			//모든 연산이 끝난 후 사용한 연산자를 다시 추가시켜 원상태로 복귀
			result = tmp;			//이전 연산값 불러온 후 다른 경우의 연산 수행
		}
	}
}

int main() {
	cin >> N;
	num = new int[N];
	for (int i = 0; i < N; i++)
		cin >> num[i];
	for (int i = 0; i < 4; i++)
		cin >> op[i];

	result = num[0];
	operation(1);
	cout << maximum << '\n' << minimum;
	return 0;
}
