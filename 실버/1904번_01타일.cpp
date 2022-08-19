#include <iostream>
using namespace std;

// int comb[1000001] = { 0, };

// int cal(int n) {  //피보나치수열
// 	if (n == 1 or n == 0)
// 		return comb[n] = 1;
// 	else if (comb[n])
// 		return comb[n];
// 	else
// 		return comb[n] = (cal(n - 1) + cal(n - 2)) % 15746;
// }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
// 	cout << cal(N);
	
	int* comb = new int[N+1];
	for(int i=0;i<=N;i++){
		if (i == 1 or i == 0)
			comb[i] = 1;
		else
			comb[i] = (comb[i - 1] + comb[i - 2]) % 15746;
	}
	cout << comb[N];

	return 0;
}
