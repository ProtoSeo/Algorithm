/*
문제
인하대 컴퓨터 공학과에 재학 중인 이산이는 오랜만에 미팅을 나가 볼까 한다. 미팅은 N명이 원탁에 앉아서 진행된다고 한다. 
질투가 난 이산이 친구 명기는 X의 저주를 걸었다. 
그 저주는 N명이 동시에 2명씩 짝을 지어 악수할 때 사람의 팔이 교차되거나 한 사람이라도 악수를 하지 못하면 그 미팅은 실패하게 되는 저주다.
하지만 명기는 이산이에게 저주를 풀 기회를 주었다. 미팅에 성공할 경우의 수를 구하여 큰소리로 외치면 저주가 풀린다. 
하지만 이산이는 계산 능력이 부족해서 당신에게 도움을 청했다. 이산이가 걸린 저주를 풀어주는 프로그램을 만들어주자.

입력
첫째 줄에 미팅에 참가하는 사람의 수 N 이 주어진다. 이 값은 10,000이하의 짝수이다.

출력
미팅에 성공하는 경우의 수를 987654321로 나눈 나머지를 출력한다.
*/
//카탈란 수 + 수열 사이트 => https://oeis.org/
#include<iostream>
#include<vector>
#define mod 987654321
using namespace std;

long long d[50001] = {1,1,2,5,14,0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,j;
    cin >>n;
    n/=2;
    for(i=5; i<=n; i++){
        d[i]=0;
        for(j=0; j<i; j++){
            d[i]+=((d[j]%mod)*(d[i-1-j]%mod))%mod;
        }
        d[i] %= mod;
    }
    cout << d[n];
}