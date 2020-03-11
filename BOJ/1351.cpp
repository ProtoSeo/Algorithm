/*
문제
무한 수열 A는 다음과 같다.

A0 = 1
Ai = A⌊i/P⌋ + A⌊i/Q⌋ (i ≥ 1)
N, P와 Q가 주어질 때, AN을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 3개의 정수 N, P, Q가 주어진다.

출력
첫째 줄에 AN을 출력한다.

제한
0 ≤ N ≤ 10^12
2 ≤ P, Q ≤ 10^9
*/
#include<iostream>
#include<map>
using namespace std;
long long n,p,q;
map<long long,long long> m;

long long seq(long long i){  
    if(m[i]){
        return m[i];
    }else{
        return m[i]= seq(i/p)+ seq(i/q);
    }
}
int main(){     //문제에 주어진 점화식을 map을 이용해서 풀면 된다.
                //배열에 저장하지 않는 이유는 범위가 큰것도 있지만, 배열로 다 만들었다 하더라도 실제적으로 사용을 하는 것은 적기 때문이다.
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    m[0] =1;
    cin >> n >> p >> q;
    cout << seq(n);
}