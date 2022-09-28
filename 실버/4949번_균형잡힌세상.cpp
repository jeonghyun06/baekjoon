#include <iostream>
using namespace std;

int main() {

	int size = 0;
	char s[101];
	cin.getline(s, 100, '.');
	char c[100]{};

	while (s[0]) {
		size = 0;
		for (int i = 0; s[i]; i++) {
			if (s[i] == '(' || s[i] == '[') {
				c[size] = s[i];
				size++;
			}
			else if (s[i] == ')') {
				if (size > 0 && c[size - 1] == '(')
					size--;
				else {
					size = 1;
					break;
				}
			}
			else if (s[i] == ']') {
				if (size > 0 && c[size - 1] == '[')
					size--;
				else {
					size = 1;
					break;
				}
			}
		}
		if (size)
			cout << "no" << '\n';
		else
			cout << "yes" << '\n';
		cin.ignore();
		cin.getline(s, 100, '.');
	}
}
