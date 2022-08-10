#include <iostream>
#include <algorithm>
using namespace std;

class Member {    //회원 class
public:
	int age;
	string name;
	int enter;
};

bool compare(Member fir, Member sec) {    //사용자지정 정렬함수
	if (fir.age == sec.age) {               //나이가 같으면 가입순서대로
		return fir.enter < sec.enter;
	}
	return fir.age < sec.age;               //오름차순정렬(뒤의 것이 더 크도록)
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	Member* members = new Member[N];
	for (int i = 0; i < N;i++) {
		cin >> members[i].age >> members[i].name;
		members[i].enter = i;
	}

	sort(members, members + N, compare);  //정렬
	for (int i = 0; i < N; i++) {
		cout << members[i].age << ' ' << members[i].name<<'\n';
	}
	return 0;
}
