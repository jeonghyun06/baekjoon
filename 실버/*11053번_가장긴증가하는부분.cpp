#include <iostream>
using namespace std;

int main() {

	int n;
	cin >> n;

	int* length = new int[n];
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int m = 0;
	for (int k = 0; k < n; k++) {
		length[k] = 1;	//k번째 수에서 끝나는 부분수열의 개수
		for (int i = 0; i < k; i++) {
			if (arr[i] < arr[k]) {	//0부터 k까지 중 어디서 여기로 오는게 최대인지 찾음.
				length[k] = max(length[k], length[i] + 1);	
			}
		}
		m = max(m, length[k]);
	}

	cout << m;

	return 0;
}

// #include <iostream>
// using namespace std;

// int main() {
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
// 	cout.tie(0);

// 	int N;
// 	cin >> N;
// 	int** numbers = new int*[N];
// 	for (int i = 0; i < N; i++) {
// 		numbers[i] = new int[3]{ 0,1,N-1};	//{나의 숫자, 조건을 만족하는 나보다 큰 수의 개수, cnt가 가장 큰 애의 idx}
// 		cin >> numbers[i][0];
// 	}
// 	for (int i = N-1; i >=0; i--) {	//오른쪽에서부터
// 		for (int j = i + 1; j < N; j++) {
// 			if (numbers[j][0] > numbers[i][0]) {
// 				numbers[i][2] = numbers[j][1] > numbers[numbers[i][2]][1] ? j : numbers[i][2];//idx가 나보다 큰 것 중 cnt가 가장 큰 애의 idx 저장
// 				numbers[i][1]++; //자기보다 큰 원소의 개수를 셈.	.
// 			}
// 		}
// 	}
// 	int m = 0;
// 	int cnt = 0;
// 	for (int i = 0; i < N; i++) {
// 		int tmp = i;
// 		cnt = 0;
// 		while (numbers[i][1]!=1) {
// 			i = numbers[i][2];
// 			cnt++;
// 		}
// 		m = max(m, cnt);
// 		i = tmp;
// 	}

// 	cout << m + 1;
// }
