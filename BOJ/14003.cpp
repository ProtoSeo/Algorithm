/*
문제
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 30, 50} 이고, 길이는 4이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (-1,000,000,000 ≤ Ai ≤ 1,000,000,000)

출력
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

둘째 줄에는 정답이 될 수 있는 가장 긴 증가하는 부분 수열을 출력한다.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#define INF 2100000000
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n,i,max=0;
    cin >>n;
    vector<int> vt;
    vector<pair<int,int>> res;
    stack<int> ans;
    vt.push_back(-INF);
    for(i=1;i<=n;i++){  //LIS O(nlogn) 알고리즘 
        int x;
        cin >>x;
        if(vt.back() < x){  
            vt.push_back(x);
            max++;
            res.push_back({x,max}); //이 문제에서는 LIS의 순서도 구해야 하므로 max값과 함께 x를 pair로 저장한다.
        }else{
            auto it = lower_bound(vt.begin(), vt.end(), x); 
            *it = x;
            res.push_back({x,it-vt.begin()});   //순서를 구하기 위해서 여기서 max를 넣으면 맞지 않으므로 해당 배열의 칸이 max일것이다.
        }
    }
    for(auto it = res.rbegin();it!=res.rend();it++){    //뒤에서 앞으로 가는 반복문
        if(max == 0) break;
        else if(it->second == max){ //뒤에서부터 max값에 맞는 값을 하나씩 저장한다.
            ans.push(it->first);
            max--;
        }
    }
    max = ans.size();
    cout << max <<'\n';
    while(!ans.empty()){
        cout<< ans.top() << ' ';
        ans.pop();
    }
}   