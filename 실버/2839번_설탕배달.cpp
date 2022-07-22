#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N;
	int result=-1;
	cin>>N;
	int a = N%5;
	if(a){						//5kg 뭉치만으로 배달이 가능한지 판단
		while(a<=N){ 				//그렇지 않으면 5씩 더하면서 3으로 나누어 떨어지는 경우 확인
			if(a%3==0){ 			// 나누어 떨어지면 -> 최소경우
				result=a/3+(N-a)/5;
				break;
			}
			a=a+5;
		}
	}
	else
		result = N/5;
	
	cout<<result;
	return 0;
}
