/*
문제
2차원 좌표 평면 위에 있는 점 3개 P1, P2, P3가 주어진다. P1, P2, P3를 순서대로 이은 선분이 어떤 방향을 이루고 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 P1의 (x1, y1), 둘째 줄에 P2의 (x2, y2), 셋째 줄에 P3의 (x3, y3)가 주어진다. 
(-10,000 ≤ x1, y1, x2, y2, x3, y3 ≤ 10,000) 모든 좌표는 정수이다. P1, P2, P3의 좌표는 서로 다르다.

출력
P1, P2, P3를 순서대로 이은 선분이 반시계 방향을 나타내면 1, 시계 방향이면 -1, 일직선이면 0을 출력한다.
*/
#include<iostream>
using namespace std;
// 참고자료 : https://www.acmicpc.net/blog/view/27
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {   //삼각형의 넓이를 세 좌표를 이용해서 구하는 공식을 이용함
    int temp = x1*y2+x2*y3+x3*y1;
    temp = temp - y1*x2-y2*x3-y3*x1;
    //cout << abs(temp)/2 ;     삼각형의 넓이 출력
    if (temp > 0) {     //반시계 방향
        return 1;
    } else if (temp < 0) {  //시계 방향
        return -1;
    } else {    //일직선
        return 0;
    }
}

int main() {
	ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int x1,y1,x2,y2,x3,y3;
    cin >> x1>>y1>>x2>>y2>>x3>>y3;  //좌표를 입력
    cout << ccw(x1,y1,x2,y2,x3,y3);
}