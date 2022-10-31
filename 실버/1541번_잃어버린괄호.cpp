#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string expression;
	vector<int> numbers;
	vector<char> oper;
	int num = 0;
	cin >> expression;
	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] >= 48 && expression[i] < 58) {
			num = num * 10 + expression[i] - 48;
		}
		else {
			numbers.push_back(num);
			oper.push_back(expression[i]);
			num = 0;
		}
	}
	numbers.push_back(num);

	for (int i = 0; i < oper.size(); i++) {
		if (oper[i] == '+') {
			numbers[i + 1] += numbers[i];
			numbers[i] = 0;
		}
	}
	bool s = false;
	int sum = 0;
	for (int i = 0; i < numbers.size(); i++) {
		if (s) {
			sum -= numbers[i];
		}
		else if (numbers[i] != 0) {
			sum = numbers[i];
			s = true;
		}
	}
	cout << sum;

	return 0;
}
