#include <iostream>
#include <string>
using namespace std;

int main() {
	string A, B, sum = "";
	cin >> A >> B;
	if (A.length() > B.length()) { 					//항상 B의 자리수가 A의 자리수보다 크거나 같게 함
		string tmp = A;
		A = B;
		B = tmp;
	}
	string Btmp = B.substr(B.length() - A.length()); 		//자리수가 같은 부분끼리 계산
	int u = 0; 							//덧셈 중 올림되는 것 확인
	for (int i = A.length() - 1; i >= 0; i--) {
		if (u) { 						//이전 셈에서 올림이 있으면 
			sum = to_string((int)A[i] + (int)Btmp[i] + u - 48 * 2) + sum.substr(1);
		}
		else
			sum = to_string((int)A[i] + (int)Btmp[i] - 48 * 2) + sum;
		if ((int)A[i] + (int)Btmp[i]-48*2 +u>= 10) 		//올림 확인
			u = 1;
		else
			u = 0;
	}
  
	for (int i = B.length() - A.length() - 1; i >= 0; i--) {	 //자리수가 넘치는 부분 계산
		if (u)
			sum = to_string((int)B[i] + u - 48) + sum.substr(1);
		else
			sum = B[i] + sum;
		if ((int)B[i] + u - 48 >= 10)
			u = 1;
		else
			u = 0;
	}
	cout << sum;

	return 0;
}
