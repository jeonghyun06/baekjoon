#include <iostream>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	int* A = new int[N];
	int* lengthF = new int[N];
	int* lengthB = new int[N];
	int m = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int k = 0; k < N; k++) {
 		lengthF[k] = 1;
		for (int i = 0; i < k; i++) {
			if (A[i] < A[k]) {
				lengthF[k] = max(lengthF[k], lengthF[i] + 1);
			}
		}
	}
	for (int k = N - 1; k >= 0; k--) {
		lengthB[k] = 1;
		for (int i = N - 1; i > k; i--) {
			if (A[i] < A[k]) {
				lengthB[k] = max(lengthB[k], lengthB[i] + 1);
			}
		}
	}
	for(int k=0;k<N;k++)
		m = max(m, lengthF[k] + lengthB[k]);
	cout << m-1;
	return 0;
}
