/*
백준 15829번 : Hashing
https://www.acmicpc.net/problem/15829
*/
#include<iostream>
#define ll long long
#define MOD 1234567891
using namespace std;
ll ary[51] = {1,31,961,},sum =0,i,n;
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    string s;
    cin >> n>> s;
    for(i=3;i<=n;i++) ary[i] = (ary[i-1]%MOD * 31)%MOD; //미리 31의 n승까지 modulo계산을 해놓는다.
    for(i=0;i<n;i++){   // 해쉬함수 수식의 시그마 부분을 계산한다.
        //덧셈과 곱셈할때 modulo 성질에 유의 하여서 계산한다.
        sum += (ary[i]*((s[i]-'a'+1)%MOD))%MOD;
        sum%=MOD; 
    }
    cout <<sum;
}