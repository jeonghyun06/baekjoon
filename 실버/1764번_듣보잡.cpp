#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	set<string> listen;
	set<string> emeqh;
	string name;
	for (int i = 0; i < N; i++) {
		cin >> name;
		listen.insert(name);
	}
	for (int i = 0; i < M; i++) {
		cin >> name;
		listen.insert(name);
		if (listen.size() == N) {
			emeqh.insert(name);
		}
		else listen.erase(name);
	}
	cout << emeqh.size() << '\n';
	for (string e : emeqh) {
		cout << e << '\n';
	}
	return 0;
}
