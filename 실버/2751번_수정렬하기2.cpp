#include <iostream>
using namespace std;

int* heapify(int root, int* s, int size) {
	int large, tmp;
	int left = 2 * root;
	int right = 2 * root + 1;
	if (left <= size && s[left] > s[root])
		large = left;
	else
		large = root;
	if (right <= size && s[right] > s[large])
		large = right;
  
	if (large != root) {
		tmp = s[large];
		s[large] = s[root];
		s[root] = tmp;
		heapify(large, s, size);
	}
	return s;

	/*int large = 2 * root;
	if (large > size)
		return s;
	int right = 2 * root + 1;
	if (right <= size && s[right] > s[large])
		large = right;
	if (s[root] < s[large]) {
		right = s[large];
		s[large] = s[root];
		s[root] = right;
		heapify(root, s, size);
	}*/
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int* S = new int[N + 1]{ 0, };
	for (int i = 1; i <= N; i++)
		cin >> S[i];
	int tmp;
	for (int i = N / 2; i > 0; i--) {   //최대힙 구현
		S = heapify(i, S, N);
	}
	cout << '\n';
	for (int i = N; i > 1; i--) {
		tmp = S[1];
		S[1] = S[i];
		S[i] = tmp;
		S = heapify(1, S, i - 1);
	}

	for (int i = 1; i <= N; i++) {
		cout << S[i] << '\n';
	}
	return 0;
}
