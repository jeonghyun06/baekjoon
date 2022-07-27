#include <iostream>
using namespace std;

int main() {
	int N, tmp;
	cin>>N;
	int five=0;
	int two=0;
	int cnt=0;
	for(int i=N;i>1;i--){
		tmp=i;
		while(tmp%5==0 or tmp%2==0){  //2와 5의 개수를 세 0이 몇 개 붙었는지 계산
			if(tmp%5==0){
				tmp/=5;
				five++;
			}
			if(tmp%2==0){
				tmp/=2;
				two++;
			}
				
		}
	}
	int answer=two>five?five:two;
	cout<<answer;
	return 0;
}
