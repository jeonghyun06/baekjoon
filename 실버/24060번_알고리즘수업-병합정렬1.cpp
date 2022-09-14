#include <iostream>
using namespace std;

int tmp[500000];
int K;

void merge(int* A, int p, int q, int r) {
	int i = p;
	int j = q + 1;
	int t = 1;
	while (i <= q && j <= r) {
		if (A[i] <= A[j])
			tmp[t++] = A[i++];
		else
			tmp[t++] = A[j++];
	}
	while (i <= q)
		tmp[t++] = A[i++];
	while (j <= r)
		tmp[t++] = A[j++];
	i = p;
	t = 1;
	while (i <= r) {
		K--;
		if (K == 0)cout << tmp[t];
		A[i++] = tmp[t++];    //저장하는 부분
	}
}

void merge_sort(int* A, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(A, p, q);
		merge_sort(A, q + 1, r);
		merge(A, p, q, r);
	}
}

int main() {
	int N;
	cin >> N >> K;
	int* A = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	merge_sort(A, 0, N - 1);
	if (K > 0)
		cout << -1;
}
