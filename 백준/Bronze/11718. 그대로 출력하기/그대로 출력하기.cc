#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char str[101];
	while (cin.getline(str,101)) {
		if (str == "") break;
		cout << str<<'\n';
	}
	
}