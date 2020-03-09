/*
문제
N개의 강의가 있다. 우리는 모든 강의의 시작하는 시간과 끝나는 시간을 알고 있다. 
이때, 우리는 최대한 적은 수의 강의실을 사용하여 모든 강의가 이루어지게 하고 싶다.

물론, 한 강의실에서는 동시에 2개 이상의 강의를 진행할 수 없고, 한 강의의 종료시간과 다른 강의의 시작시간이 겹치는 것은 상관없다. 
필요한 최소 강의실의 수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 강의의 개수 N(1≤N≤100,000)이 주어진다. 둘째 줄부터 N개의 줄에 걸쳐 각 줄마다 세 개의 정수가 주어지는데, 
순서대로 강의 번호, 강의 시작 시간, 강의 종료 시간을 의미한다. 강의 번호는 1부터 N까지 붙어 있으며, 
입력에서 꼭 순서대로 주어지지 않을 수 있으나 한 번씩만 주어진다. 강의 시작 시간과 강의 종료 시간은 0 이상 10억 이하의 정수이라고 가정한다.

출력
첫째 줄에 필요한 최소 강의실 개수를 출력한다.
*/
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,i,j,cnt=0,res=0;
    cin >> n;
    priority_queue<int,vector<int>,greater<int>> start_time;
    priority_queue<int,vector<int>,greater<int>> end_time;

    for(i=0;i<n;i++){
        int a,b,c;
        cin >> a>>b>>c;
        //시작시간과 종료시간에 맞춰서 우선순위 큐에 push한다.
        start_time.push(b); 
        end_time.push(c);
    }
    while(!start_time.empty()&&!end_time.empty()){  //
        if(start_time.top()<end_time.top()){    
            //우선순위 큐에 의해서 가장 빠른 시작시간이 가장 빠른 종료시간보다 작다면, 강의실이 하나 더 필요하게된다.
            cnt++;  //강의실 수 증가
            start_time.pop();   //  강의실을 증가시켰으므로 새로운 강의 시작시간으로 넘어간다.
            res = max(res,cnt);     //최대값을 저장하고 있도록 한다.
        }else{  //시작시간이 종료시간과 같거나 크다면 넘어간다.
            end_time.pop();
            cnt--;  //그리고 강의가 종료 된것이므로 강의실 수를 1 감소시킨다.
        }
    }
    cout << res;
}