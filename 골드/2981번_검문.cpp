#include <iostream>
#include <algorithm>  //sort
#include <cmath>      //sqrt
#include <vector>     //divisor vector
using namespace std;

int GCD(int a, int b) {
	int R = a % b;
	while (R != 0) {
		a = b;
		b = R;
		R = a % b;
	}
	return b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, diff;
	cin >> N;
	int* num = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
  sort(num, num + N);
  
	int gcd = num[1] - num[0];              //차의 최대공약수 구하기
	for (int i = 2; i < N; i++) {
		gcd = GCD(gcd, num[i] - num[i-1]);
	}

	vector<int> divisor;
	for (int i = 2; i <= sqrt(gcd); i++) {    //시간 단축을 위해 앞 절반을 먼저 구함.
		if (gcd % i == 0) {
			divisor.push_back(i);
			if (gcd / i != i)                     //제곱일 경우 하나만
				divisor.push_back(gcd / i);
		}
	}
	sort(divisor.begin(), divisor.end());     //정렬 후 출력
	for (int i = 0; i < divisor.size(); i++) {
		cout << divisor[i] << ' ';
	}
	cout << gcd;

	return 0;
}
