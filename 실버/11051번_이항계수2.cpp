#include <iostream>
using namespace std;
int bi[1000][500] = { 0, };   //다이나믹 프로그래밍

int binomal(int n, int r) {   //이항계수(파스칼의 삼각형) => nCr = n-1Cr + n-1Cr-1
	if (bi[n][r])
		return bi[n][r];
	if (r == 0 or r == n)
		return bi[n][r] = 1;
	return bi[n][r] = (binomal(n - 1, r) + binomal(n - 1, r - 1)) % 10007;  //mod 연산에서 합차곱이 성립(나누기는 성립하지 않음)
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	K = K > N - K ? N - K : K;	//계산속도를 빠르게 하기 위해 nCr = nCn-r 이용
	cout << binomal(N, K);

	return 0;
}
