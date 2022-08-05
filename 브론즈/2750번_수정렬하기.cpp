#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int tmp;
	for (int i = 0; i < N-1; i++) {       //정렬 과정 - 선택정렬과 유사하지만 최소값 찾는 과정이 더 복잡하다고 느껴짐
		for (int k = i + 1; k < N; k++) {   //25431 입력시 과정 - 1|5432 -> 1|4532 -> 1|3542 -> 1|2543 -> 12|453 -> 123|54 -> 1234|5
			if (arr[i] > arr[k]) {
				tmp = arr[k];
				arr[k] = arr[i];
				arr[i] = tmp;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}
