#include <iostream>
#include <cstring>    //strlen함수
using namespace std;

int c;

int recursion(const char* s, int l, int r) {
    c++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
    c = 0;
    return recursion(s, 0, strlen(s) - 1);
}

int main() {
    int T;
    char S[1001]; //크기를 1000으로 해줘서 틀림.
    cin >> T;
    while (T--){
        cin >> S;
        cout << isPalindrome(S) << ' '; //한줄에 처리하면 함수 실행 전 c 값이 출력됨 -> 다음 줄에 실행되도록함.
        cout << c << '\n';
    }
}
