#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int colors[4] = { 0, };
	int numbers[9] = { 0, };
	int number;
	char color;
	for (int i = 0; i < 5; i++) {
		cin >> color >> number;
		if (color == 'R') 
			colors[0]++;
		else if (color == 'B')
			colors[1]++;
		else if (color == 'Y') 
			colors[2]++;
		else
			colors[3]++;
		numbers[number - 1]++;
	}
	
	int score = 0;
	bool sameColor5 = false;
	bool sequence = false;
	int maxN = 0;
	for (int i = 0; i < 4; i++) {
		if (colors[i] == 5)
			sameColor5 = true;
	}
	for (int i = 0; i < 5; i++) {
		if (numbers[i] * numbers[i + 1] * numbers[i + 2] * numbers[i + 3] * numbers[i + 4] == 1) {
			sequence = true;
			break;
		}
	}
	for (int i = 0; i < 9; i++) {
		maxN = numbers[i] != 0 ? i+1 : maxN;
		if (numbers[i] == 4) {
			score = score < 800 + i + 1 ? 800 + i + 1 : score;
			break;
		}
		if (numbers[i] == 3) {
			score = score < 400 + i+1 ? 400 + i + 1 :score;
		}
		if (numbers[i] == 2) {
			score = score < 200 + i+1? 200 + i + 1 :score;
		}
		for (int j = i + 1; j < 9; j++) {
			if (numbers[i] == 2 && numbers[j] == 3) {
				score = score < 10 * j + i + 700+11 ? 10 * j + i + 700+11 : score;
				break;
			}
			else if (numbers[i] == 3 && numbers[j] == 2) {
				score = score < 10 * i + j + 700+11 ? 10 * i + j + 700+11 : score;
				break;
			}
			else if (numbers[i] == 2 && numbers[j] == 2) {
				score = score < 10 * j + i + 300+11? 10 * j + i + 300+11 : score;
				break;
			}
		}
		
	}

	if (sameColor5 && sequence)
		score = 900 + maxN;
	else if (sameColor5)
		score = 600 + maxN;
	else if (sequence)
		score = 500 + maxN;

	if (score == 0)
		score = 100 + maxN;
	cout << score;
	return 0;
}
