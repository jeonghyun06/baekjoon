#include <iostream>
using namespace std;

class node {
public:
	int direction;
	int length;

};

int main() {
	int K;
	int maxH = 0;
	int maxW = 0;
	node nodes[6];

	cin >> K;
	for (int i = 0; i < 6; i++) {
		cin >> nodes[i].direction >> nodes[i].length;
		if (nodes[i].direction == 1 or nodes[i].direction == 2) {   //동서방향으로 가장 긴 변
			if (i == 0 or i==1)
				maxW = i;
			else if (nodes[i].length >= nodes[maxW].length)           
				maxW = i;
		}
		else {                                                      //남북방향으로 가장 긴 변
			if (i == 0 or i == 1)
				maxH = i;
			else if (nodes[i].length >= nodes[maxH].length)
				maxH = i;
		}
	}

	int maxN = maxH > maxW ? maxH : maxW;                         //둘 중 나중에 나오는 변 찾기
	if (maxH - maxW != 1 && maxH - maxW != -1)
		maxN = 0;
	int result = nodes[maxH].length * nodes[maxW].length - nodes[(maxN + 2) % 6].length * nodes[(maxN + 3) % 6].length; //전체-사각형으로 넓이 구하기

	cout << result * K;
	return 0;
}
