#include <iostream>
#include <algorithm> //sort, upper_bound
using namespace std;

int main() {
	int N, score, P;
	cin>>N>>score>>P;
	int* rank = new int[N+1]; //이미 랭킹에 있는 점수와 태수의 점수를 저장하는 배열
	
	int tmp;
	for(int i=0;i<N;i++){
		cin>>tmp;
		rank[i]=tmp;
	}
	rank[N]=score;
	sort(rank,rank+N+1); //오름차순 정렬
  
  //태수의 점수가 랭킹에 오르지 않는 경우 
	if(N==P && rank[0]>=score){ //이미 랭킹이 꽉 차있고 최하위 순위의 점수보다 태수의 점수가 낮거나 같을때
		cout<<-1;
	}
	else{
		int a = upper_bound(rank,rank+N+1,score) - rank; //score보다 높은 경우 위치 찾기(오름차순에서)
		cout<<N + 2 - a; //순위는 내림차순이므로 N에서 뺀다. N-(a-1) + index는 0부터이므로 +1
	}
	return 0;
}
