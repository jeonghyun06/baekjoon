#include <iostream>
using namespace std;

int count(int num, int divBy) {       //num!에서 divBy가 몇 거듭제곱 존재하는지 세는 함수 -> 이 문제의 핵심★
	int cnt = 0;
	while (num / divBy > 0) {           //divBy가 5일 때, 5의 배수는 5를 1개 포함, 5^2의 배수는 5를 2개 포함 ,...
		cnt += num / divBy;               //따라서 5로 나누었을 때의 몫을 계속해서 더하면 그 개수가 됨.
		num /= divBy;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int numer2, numer5, deno2, deno5;   //분모와 분자의 2, 5의 개수를 각각 세는 변수
	cin >> n >> m;
  
	numer2 = count(n, 2);   //분자
	numer5 = count(n, 5);
	deno2 = count(n - m, 2) + count(m, 2);    분자
	deno5 = count(n - m, 5) + count(m, 5);

	int answer = numer2 - deno2 > numer5 - deno5 ? numer5 - deno5 : numer2 - deno2;   //둘 중 개수가 더 적은 것을 출력
	cout << answer;

	return 0;
}
