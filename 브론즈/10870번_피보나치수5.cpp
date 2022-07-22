#include <iostream>
using namespace std;

int recursion(int N){
	if(N==0)
		return 0;
	if(N==1 || N==2)
		return 1;
  
	return recursion(N-1)+recursion(N-2);
}

int main() {
	int N;
	cin>>N;
	cout<<recursion(N);
	
	return 0;
}
