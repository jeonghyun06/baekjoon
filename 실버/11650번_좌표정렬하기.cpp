#include <iostream>
#include <algorithm>
using namespace std;

class Point {
public:
	int x, y;
};

bool compare(Point fir, Point sec) {
	if (fir.x == sec.x) {
		return fir.y < sec.y;
	}
	return fir.x < sec.x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	Point* points = new Point[N];
	for (int i = 0; i < N; i++) {
		cin >> points[i].x >> points[i].y;
	}
	sort(points, points + N, compare);

	for (int i = 0; i < N; i++) {
		cout << points[i].x << ' ' << points[i].y << '\n';
	}
	return 0;
}
