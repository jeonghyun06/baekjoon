//https://www.acmicpc.net/problem/1065
#include <iostream>
using namespace std;

int main() {
	int N, h, t, o, cnt;
	cin>>N;
	if(N<100) //두자리 수는 무조건 등차수열
		cout<<N;
	else{
		for(cnt=0;N>99;N--){ //100이상이면 각 자리수 등차확인
			h = N/100;
			t = (N%100)/10;
			o = (N%100)%10;
			if(h-t==t-o) //등차확인
				cnt++;
		}
		cout<<99+cnt; //100이하의 한수 99개
	}
	return 0;
}
