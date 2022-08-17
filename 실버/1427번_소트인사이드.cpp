#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int counts[10]{0,};
	string numbers;
	cin >> numbers;
	for (int i = 0; i < numbers.length(); i++) {
		counts[numbers[i]-48]++;
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < counts[i]; j++)
			cout << i;
	}
	return 0;
}
