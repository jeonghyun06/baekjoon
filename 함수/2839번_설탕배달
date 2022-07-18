#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N;
	int result=-1;
	cin>>N;
	int a = N%5;
	if(a){
		while(a<=N){
			if(a%3==0){
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
