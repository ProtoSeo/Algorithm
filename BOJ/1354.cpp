/*
문제
무한 수열 A는 다음과 같다.

Ai = 1 (i ≤ 0)
Ai = A⌊i/P⌋-X + A⌊i/Q⌋-Y (i ≥ 1)
N, P, Q, X, Y가 주어질 때, AN을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 5개의 정수 N, P, Q, X, Y가 주어진다.

출력
첫째 줄에 AN을 출력한다.

제한
0 ≤ N ≤ 10^13
2 ≤ P, Q ≤ 10^9
0 ≤ X, Y ≤ 10^9
*/
#include<iostream>
#include<map>
using namespace std;
long long n,p,q,x,y;
map<long long,long long> m;
long long seq(long long i){  
    if(i<=0){
        return 1;
    }else if(m[i]){
        return m[i];
    }else{
        return m[i]= seq((i/p)-x)+ seq((i/q)-y);
    }
}
int main(){     //문제에 주어진 점화식을 map을 이용해서 풀면 된다.
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    m[0] = 1;
    cin >> n >> p >> q>>x>>y;
    cout << seq(n);
}