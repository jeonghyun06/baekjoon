#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> a >> b;
	while (a * b) {
		if (a % b == 0)
			cout << "multiple" << '\n';
		else if (b % a == 0)
			cout << "factor" << '\n';
		else
			cout << "neither" << '\n';
		cin >> a >> b;
	}
	return 0;
}
