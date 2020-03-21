/*
문제
주식투자를 좋아하는 정인이는 주가의 오름세를 살펴보려고 한다.

정인이는 n일 동안 매일 주가를 적어놓았고, 여기서 오름세를 찾아보려고 한다.

n일 동안의 주가를 p1, p2, ..., pn이라고 했을 때, 오름세란 부분수열 pi1 < pi2 < ... < pik (i1 < i2 < ... ik)을 말한다.

n일 동안 주가가 주어졌을 때, 가장 긴 오름세를 찾는 프로그램을 작성하시오.

입력
입력은 여러개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스의 첫째 줄에는 주가를 관찰한 날의 수 N (N ≤ 100000)이 주어진다. 
둘째 줄에는 관찰한 주가가 첫 날부터 순서대로 주어진다. 주가는 한 개 이상의 공백으로 구분되어 있다. 주가는 100,000보다 작거나 같은 자연수이다.

출력
각 테스트 케이스에 대해서 입력으로 주어진 주가의 가장 긴 오름세의 길이를 출력한다.
*/
#include<iostream>
#include<algorithm>
#include<vector>
#define INF 2100000000
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n,i;
    while(cin>> n){ //n에 EOF가 입력이 들어올때까지 반복한다.
        int max=0;
        vector<int> vt;
        vt.push_back(-INF);
        for(i=1;i<=n;i++){  //LIS O(nlogn) 알고리즘
            int x;
            cin >> x;
            if(vt.back() < x){
                vt.push_back(x);
                max ++;
            }else{
                auto it = lower_bound(vt.begin(),vt.end(),x);
                *it = x;
            }
        }
        cout<< max<<'\n';
    }
}
