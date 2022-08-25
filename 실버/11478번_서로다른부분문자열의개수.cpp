#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S;
	string tmp;
	set<string> substring;
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		for (int j = 1; j <= S.size()-i; j++) {
			tmp = S.substr(i, j);   //substr 함수 -> substr(시작위치, 개수)
			substring.insert(tmp);
		}
	}
	cout << substring.size();
	return 0;
}
