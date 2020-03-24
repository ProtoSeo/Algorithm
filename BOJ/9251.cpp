/*
문제
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 
모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

입력
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

출력
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.
*/
#include<iostream>
#include<string>
using namespace std;
int d[1001][1001];
int main(){
    string a,b;
    cin >> a >> b;
    //LCS O(n^2) 알고리즘 (문자열 두개를 놓고 2차원 배열을 그린다고 생각하자)
    for(int i=1;i<=a.length();i++) {   // 첫번째 string 의 길이만큼 반복
        for(int j=1;j<=b.length();j++) {    //두번째 string 의 길이만큼 반복
            if (a[i-1] == b[j-1]) {    //문자가 같은경우
                //이전 대각선 쪽에서 저장되어있는 수열의 길이보다 1 길어질수 있으므로 대각선의 값에서 1 증가시켜준다. 
                d[i][j] = d[i-1][j-1] + 1;
            } 
            else { 
                d[i][j] = max(d[i][j-1], d[i-1][j]);    //왼쪽과 위쪽중에서 더 큰 값을 받아서 저장하도록 한다.
            } 
        } 
    }
    cout << d[a.length()][b.length()];  //결국 맨 마지막에는 가장큰 수열의 값이 저장될 것이다.
}