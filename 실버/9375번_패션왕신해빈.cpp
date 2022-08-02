#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n;
	string cloth, Ctype;
	int cases;
	cin >> T;
	while (T--) {
		cin >> n;
		vector<string> type;
		vector<int> cnt;
		while (n--) {
			cin >> cloth >> Ctype;
			if (type.end() == find(type.begin(), type.end(), Ctype)) {  //이미 있는 종류의 옷인지 판단
				type.push_back(Ctype);                                    //없는 종류의 옷이라면 추가
				cnt.push_back(1);
			}
			else
				cnt[find(type.begin(), type.end(), Ctype) - type.begin()]++;  //있는 종류의 옷이라면 개수 증가
		}
		cases = 1;
		for (int i = 0; i < cnt.size(); i++) {
			cases *= cnt[i]+1;        //홀수의 개수를 계산하듯 안입는 경우까지 cnt+1 개의 경우를 모두 곱

		}
		cout << cases-1 << '\n';    //모두 벗은 경우를 제하므로 -1
	}
	return 0;
}
