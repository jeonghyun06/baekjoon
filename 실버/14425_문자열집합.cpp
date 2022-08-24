#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	string s;
	set<string> S;
	for (int i = 0; i < N; i++) {
		cin >> s;
		S.insert(s);
	}
	int cnt = 0;
	while (M--) {
		cin >> s;
		S.insert(s);
		if (S.size() == N)
			cnt++;
		else S.erase(s);  //지우지 않고 하다보니 원래 문자열 외의 것이 반복되서 나오면 중복이 있는 것으로 판단되어 틀림. -> 중복되지 않으면 지우도록
	}
	cout << cnt;
	return 0;
}
