#include <iostream>
using namespace std;

class Stack {
private:
	int stack[10001]{ 0, };
	int s = 0;
public:
	void push(int X) {
		stack[s] = X;
		s++;
	}
	int pop() {
		if (!s)
			return -1;
		s--;
		return stack[s];
	}
	int size() {
		return s;
	}
	int empty() {
		if (s)
			return 0;
		return 1;
	}
	int top() {
		if (!s)
			return -1;
		return stack[s-1];
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, x;
	cin >> N;
	string s;
	Stack stack;
	while (N--) {
		cin >> s;
		if (s == "push") {
			cin >> x;
			stack.push(x);
		}
		else if (s == "pop") {
			x = stack.pop();
			cout << x<<'\n';
		}
		else if (s == "size") {
			x = stack.size();
			cout << x << '\n';
		}
		else if (s == "empty") {
			x = stack.empty();
			cout << x << '\n';
		}
		else {
			x = stack.top();
			cout << x << '\n';
		}
	}
}
