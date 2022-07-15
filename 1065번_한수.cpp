#include <iostream>
using namespace std;

int main() {
	int N, h, t, o, cnt;
	cin>>N;
	if(N<100)
		cout<<N;
	else{
		for(cnt=0;N>99;N--){
			h = N/100;
			t = (N%100)/10;
			o = (N%100)%10;
			if(h-t==t-o)
				cnt++;
		}
		cout<<99+cnt;
	}
	return 0;
}
