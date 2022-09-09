#include <iostream>
using namespace std;

int sdoku[9][9]{ {0,}, };
int col[9][10];
int row[9][10];
int box[9][10];
int cnt = 0;

class Pair {
public:
	int cc;
	int rr;
};

Pair blank[81]; //구해야 할 부분을 담는 배열

int Sdoku(int c,int flag) {
	if (c == cnt) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sdoku[i][j]<<' ';
			}
			cout << '\n';
		}
		return 1; //flag를 통해 1개만 출력하도록 함.
	}
	int i = blank[c].cc;
	int j = blank[c].rr;
	for (int k = 1; k <= 9; k++) {  //k : 그 자리에 올 수 있는 숫자(1~9) 
		if (!(col[i][k] + row[j][k] + box[(i / 3) * 3 + (j / 3)][k])) { //만약 올 수 있으면
			sdoku[i][j] = k;  //위치시키고
			col[i][k] = 1;    //행, 열, 박스 안의 숫자를 사용되었다고 표시.
			row[j][k] = 1;
			box[(i / 3) * 3 + (j / 3)][k] = 1;
			flag = Sdoku(c + 1, flag);  //개수를 추가시켜 재귀
			if (flag) break;    //하나의 경우만 출력하므로 flag가 1이면 break
			sdoku[i][j] = 0;    //다시 초기화
			col[i][k] = 0;
			row[j][k] = 0;
			box[(i / 3) * 3 + (j / 3)][k] = 0;
		}
	}
	
  return 0;
  
	//for (int i = column; i < 9; i++) {    //맨 처음 코드로 순환하면서 0인 부분을 찾고 그 부분에 알맞는 수를 찾았다.
	//	for (int j = 0; j < 9; j++) {       //그 과정에서 시간초과 발생(3중 for문) 
	//		if (!flag && !sdoku[i][j]) {      //그래서 맨 처음 입력부터 0인 입력을 저장하는 배열을 만듦
	//			for (int k = 1; k <= 9; k++) {
	//				if (!(col[i][k] + row[j][k] + box[(i / 3) * 3 + (j / 3)][k])) {
	//					sdoku[i][j] = k;
	//					col[i][k] = 1;
	//					row[j][k] = 1;
	//					box[(i / 3) * 3 + (j / 3)][k] = 1;
	//					flag = Sdoku(c + 1,flag,i);
	//					if (flag) break;
	//					sdoku[i][j] = 0;
	//					col[i][k] = 0;
	//					row[j][k] = 0;
	//					box[(i / 3) * 3 + (j / 3)][k] = 0;
	//				}
	//			}
	//		}
	//	}
	//}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sdoku[i][j];
			if (!sdoku[i][j]) { //0인 입력이 들어오면 해당 좌표 저장
				blank[cnt].cc = i;
				blank[cnt].rr = j;
				cnt++;
			}
			col[i][sdoku[i][j]] = 1;//각 행, 열, 박스 안에 어떤 숫자가 있는지 저장
			row[j][sdoku[i][j]] = 1;
			box[(i/3)*3+(j/3)][sdoku[i][j]] = 1;
		}
	}
	Sdoku(0,0);
	return 0;
}
