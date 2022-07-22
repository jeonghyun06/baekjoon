#include <iostream>
using namespace std;

int hanoi(int n){ 					//횟수 계산 - An = 2 * An-1 + 1
	if(n==1)
		return 1;
	return 1+2*hanoi(n-1);
}

void ToHanoi(int n, int from, int to, int ano){		//순서 출력
	if(n==1) 					//판이 1개일 때
		cout<<from<<' '<<to<<'\n';
	else if(n==2){ 					//판이 2개일 때
		cout<<from<<' '<<ano<<'\n';
		cout<<from<<' '<<to<<'\n';
		cout<<ano<<' '<<to<<'\n';
	}
	else{
		ToHanoi((n-1)/2,from,ano,to); 		//절반 나누어 윗부분 움직이는 순서
		ToHanoi(1,from,to,ano); 		//맨 밑 판 움직임
		ToHanoi((n-1)/2,ano,to,from); 		//아랫부분 움직이는 순서
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
  
	int N;
	cin>>N;
	cout<<hanoi(N)<<'\n';
	ToHanoi(hanoi(N),1,3,2);
	
	return 0;
}
