/*
문제
n가지 종류의 동전이 있다. 각각의 동전이 나타내는 가치는 다르다. 이 동전을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 
그 경우의 수를 구하시오. 각각의 동전은 몇 개라도 사용할 수 있다.

사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.

입력
첫째 줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 다음 n개의 줄에는 각각의 동전의 가치가 주어진다. 
동전의 가치는 100,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 경우의 수를 출력한다. 경우의 수는 2^31보다 작다.
*/
#include<iostream>
using namespace std;
int coin[100],d[10001];
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int i,j,n,k;
    cin >>n>>k;
    for(i=0;i<n;i++) cin >> coin[i];    //입력
    d[0]=1;
    for(i=0;i<n;i++){   //첫번째 동전부터 마지막 동전까지 반복
        for(j=1;j<=k;j++){  //1부터 k원 까지 동전들을 사용해서 얼마나 
            if (j >= coin[i]) { //해당 금액이 확인하는 동전보다 큰지 확인(작으면 해당 동전으로 금액을 만들 수 없다.)
                //현재 금액에 어떤 동전을 사용해서 금액을 만들고 남은 돈도 동전으로 만들어진 수를 더한다.
                d[j] += d[j-coin[i]]; 
            }
        }
    }
    cout << d[k];
}