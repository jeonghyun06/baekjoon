#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool compare(string fir, string sec) {
	if (fir.length() == sec.length()) {
		return fir < sec;
	}
	return fir.length() < sec.length();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
  
  //시간 단축 후 코드 - 출력시 동일 원소 제외
	string* words = new string[N];
	for (int i = 0; i < N; i++) {     //입력은 바로바로 받고
		cin >> words[i];
	}
	sort(words, words+N, compare);    //정렬한 후에
	cout << words[0] << '\n';
	for (int i = 1; i < N; i++) {
		if (words[i - 1] != words[i])   //같은 원소들을 출력하지 않도록 함
			cout << words[i] << '\n';
	}
  
  //처음 코드 - 입력시 동일 원소 입력을 아예 받지 않음
  vector<string> words;
	while (N--) {
		cin >> word;
		if (find(words.begin(), words.end(), word) == words.end())  //find를 매번 수행하다보니 시간이 매우 오래 소요됨
			words.push_back(word);
	}
	sort(words.begin(), words.end(), compare);
	for (string w : words) {
		cout << w<<'\n';
	}
  
	return 0;
}
