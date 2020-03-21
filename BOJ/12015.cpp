/*
문제
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 30, 50} 이고, 길이는 4이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.
둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000,000)

출력
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
*/
//참고자료 : https://jason9319.tistory.com/113
#include<iostream>
#include<algorithm>
#include<vector>
#define INF 2100000000
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n,i,ans=0;
    cin >> n;
    vector<int> vt;     //값을 저장할 vector
    vt.push_back(-INF);     //역전이 되지 않도록 최솟값을 입력
    for (int i = 0; i < n; i++) {   
        int x;
        cin >> x;   //입력을 받음
        
        if (vt.back() < x) {    //현재의 vector에 가장 마지막의 값보다 크다면
            vt.push_back(x);    //vector에 저장한다.
               ans++;
        }
        else {  
            /*현재의 vector에 가장 마지막의 값보다 작거나 같다면
            lower_bound함수를 이용해서 vector에 저장되어 있는 값중 x가 가장 들어갈만한 위치를 찾아서
            해당 위치에 x를 넣어서 저장한다.(따라서 vector 에는 LIS수열이 저장되는 것이 아니다.)
            lower_bound가 이진탐색을 통해서 찾으므로 시간 복잡도가 O(nlogn)으로 줄게된다.
            lower_bound는 찾으려하는 key값이 없으면 key값보다 큰 가장 작은 값을 찾는다.*/
            auto it = lower_bound(vt.begin(), vt.end(), x);     //iterator를 반환하는것을 알아야한다.
            *it = x;    //해당 값을 x로 교체
        }
    }
    cout <<ans;
}