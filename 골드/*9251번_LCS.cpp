#include <iostream>
using namespace std;

int LCS[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string A;
	string B;
	cin >> A >> B;
	for (int i = 0; i <= A.length(); i++) {
		for (int j = 0; j <= B.length(); j++) {
			if (!(i * j))
				LCS[i][j] =  0;
			else if (A[i-1] == B[j-1])
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
		}
	}
	cout << LCS[A.length()][B.length()];
	return 0;
}
