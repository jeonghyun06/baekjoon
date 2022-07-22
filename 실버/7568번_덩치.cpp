#include <iostream>
using namespace std;

int main() {
	int N, x, y;
	cin>>N;
	int** people = new int*[N];
	for(int i=0;i<N;i++){
		people[i]= new int[2];
		cin>>people[i][0]>>people[i][1];                            //입력
	}
	for(int i=0;i<N;i++){
		int cnt=0;
		for(int k=0;k<N;k++){
			if(people[i][0]<people[k][0]&&people[i][1]<people[k][1])  //덩치비교
				cnt++;
		}
		cout<<cnt+1<<' ';
	}
	
	return 0;
}
