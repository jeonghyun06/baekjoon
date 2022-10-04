#include <iostream>
#include <algorithm>
using namespace std;

class Pair {
public:
	int A;
	int B;
};

bool compare(Pair one, Pair two) {
	return one.A > two.A;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	Pair* line = new Pair[N];
	for (int i = 0; i < N; i++) {
		cin >> line[i].A >> line[i].B;
	}

	sort(line,line+N, compare); //정렬

	int m = 0;

	int* length = new int[N];
	for (int k = 0; k < N; k++) {
		length[k] = 1;
		for (int i = 0; i < k; i++) {
			if (line[i].B > line[k].B) {
				length[k] = max(length[k], length[i] + 1);
			}

		}
		m = max(m,length[k]);
	}
	cout << N-m;
	return 0;
}
