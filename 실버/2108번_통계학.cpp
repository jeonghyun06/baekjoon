#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, number;
	cin >> N;
	int sum = 0;
	vector<int> numbers;
	for (int i = 0; i < N; i++) {
		cin >> number;
		numbers.push_back(number);
		sum += number;
	}
	sort(numbers.begin(), numbers.end());
	vector<int> maxFreqs;
	int maxFreq = 0;
	for (int i = 0; i < N;) {
		auto start = find(numbers.begin(), numbers.end(), numbers[i]);
		auto end = upper_bound(numbers.begin(), numbers.end(), numbers[i]);
		if (maxFreq == end - start) {
			maxFreqs.push_back(numbers[i]);
		}
		else if(maxFreq<end-start){
			maxFreq = end - start;
			maxFreqs.clear();
			maxFreqs.push_back(numbers[i]);
		}
		i += end - start;
	}
	if (maxFreqs.size() == 1)
		maxFreqs.push_back(maxFreqs[0]);

	cout << round(double(sum) / N) + 0 << '\n';
	cout << numbers[N / 2]<<'\n';
	cout << maxFreqs[1] << '\n';
	cout << numbers[N - 1] - numbers[0];
	return 0;
}
