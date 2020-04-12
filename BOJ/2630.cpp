/*
백준 2630번 : 색종이 만들기
https://www.acmicpc.net/problem/2630
*/

#include<iostream>
using namespace std;
int blue,white,n, dx[4] = { 0,0,1,1 }, dy[4] = { 0,1,0,1 };
char a[129][129];
// 분할정복을 통해서 종이를 판별한다.
char rec(int size, int x, int y) {
	if (size == 1) {    //기저조건 : 마지막 칸이라면 현재 종이의 색을 반환한다.
        return a[x][y];
	}else{
        int temp = size / 2,blueCnt=0,whiteCnt=0,finishCnt=0;
        for (int j = 0; j < 4; j++) {   //분할을 해서 다시 재귀를 반복하도록 하는 반복문
		    char ret = rec(temp, x + dx[j] * temp, y + dy[j] * temp);
            //반환받은 조건을 통해서 작은 white와 blue의 후보의 색을 센다.
            if(ret=='0') whiteCnt++;    
            else if(ret=='1') blueCnt++;
	    }
        //작은 조각들의 색이 모두 같다면 이는 하나의 조각으로 봐도 된다.
        if(blueCnt==4)  return '1';
        else if(whiteCnt==4) return '0';
        //작은 조각들의 색이 하나라도 다르면 이는 색이 섞여 있으므로 작은 조각으로 잘라야 한다.
        else{ 
            blue += blueCnt,white += whiteCnt;
            return '2'; //2를 반환하도록 한다.(색이 섞여있다는 표시)
        }
    }
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	char res;
	int i,j;
	cin >> n;
    for (i = 1; i <= n; i++)  for (j = 1; j <= n; j++)  cin >> a[i][j]; 
	res = rec(n, 1, 1);
    //res가 하나의 색이라면 그냥 한장일 것이다.
    if(res=='0') white++;
    else if(res=='1') blue++;
    cout << white << '\n' << blue;
}