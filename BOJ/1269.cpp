/*
문제
자연수를 원소로 갖는 공집합이 아닌 두 집합 A와 B가 있다. 이때, 두 집합의 대칭 차집합의 원소의 개수를 출력하는 프로그램을 작성하시오. 
두 집합 A와 B가 있을 때, (A-B)와 (B-A)의 합집합을 A와 B의 대칭 차집합이라고 한다.

예를 들어, A = { 1, 2, 4 } 이고, B = { 2, 3, 4, 5, 6 } 라고 할 때, 
 A-B = { 1 } 이고, B-A = { 3, 5, 6 } 이므로, 대칭 차집합의 원소의 개수는 1 + 3 = 4개이다.

입력
첫째 줄에 집합 A의 원소의 개수와 집합 B의 원소의 개수가 빈 칸을 사이에 두고 주어진다. 
둘째 줄에는 집합 A의 모든 원소가, 셋째 줄에는 집합 B의 모든 원소가 빈 칸을 사이에 두고 각각 주어진다. 
각 집합의 원소의 개수는 200,000을 넘지 않으며, 모든 원소의 값은 100,000,000을 넘지 않는다.

출력
첫째 줄에 대칭 차집합의 원소의 개수를 출력한다.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
set<int> a;
set<int> b;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int i,n,m,tmp;
    cin >>n>>m;
    for(i=0;i<n;i++){   //첫번째 set에 입력을 저장한다.
        cin >> tmp;
        a.insert(tmp);
    }
    for(i=0;i<m;i++){   //두번째 set에 입력을 저장한다.
        cin >>tmp;
        b.insert(tmp);
    }
    vector<int> res;    //set_intersection을 통해서 교집합을 찾아서 해당 교집합의 크기를 빼서 차집합의 크기를 구한다.
    set_intersection(a.begin(),a.end(),b.begin(),b.end(),back_inserter(res));
    cout<<n+m-2*res.size();
}