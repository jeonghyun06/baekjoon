#include <iostream>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	long long int* A = new long long int[N + 1];
	long long int* B = new long long int[M] {0, };
	A[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		A[i] = A[i] % M;
		A[i] = (A[i] + A[i - 1])%M;
		B[A[i]]++;
	}
	long long int cnt = B[0];
	for (int i = 0; i < M; i++) {
		cnt += B[i] * (B[i]-1) / 2; //나머지가 같은 집합에서 두개를 뽑는 경우의 수 nC2)
	}
	cout << cnt;
	return 0;
}
