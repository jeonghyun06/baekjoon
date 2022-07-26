#include <iostream>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	int cnt = 1;
	int num = 666;
	int tmp;
	string numString;
	while (cnt != N) {
		num++;

		// 1번째 풀이 - 내가 푼 방식 192ms
		numString = to_string(num);
		for (int i = 0; i <= numString.length() - 3; i++) {		//모든 수를 1씩 증가시키면서 문자열로 확인
			if (numString.substr(i, 3) == "666") {
				cnt++;
				break;
			}
		}

		// 2번째 풀이 - 64ms
		if (to_string(num).find("666") != -1)					        //string의 find 함수 이용 + 2중 for문이 없어 시간 단축
			cnt++;

		// 3번째 풀이 - 24ms
		tmp = num;
		while (tmp > 100) {
			if (tmp % 1000 == 666) {                            //계산을 통해 검증하므로 시간 단축
				cnt++;
				break;
			}
			else
				tmp = tmp / 10;
		}
	}
	cout << num;

	return 0;
}
