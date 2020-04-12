/*
백준 11723번 : 집합
https://www.acmicpc.net/problem/11723
*/
#include<iostream>
using namespace std;
//bitmask로 풀어보기
bool s[21];     //true면 집합에 있는것, false면 집합에 없는 것으로 구현하였다.
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,i;
    cin >>n;
    //처음에는 set을 이용해서 풀려고 했으나, 범위가 작고, 계산의 양이 많아서 그냥 구현하였다.
    //하지만 배열을 이용하는 것보다 bitmask를 이용하는 것이 좀 더 좋을것 같다.
    while(n--){
        string cmd;
        int tmp;
        cin >> cmd;
        if(cmd=="add"){
            cin >> tmp;
            s[tmp] = true;
        }else if(cmd=="remove"){
            cin >> tmp;
            s[tmp]=false;
        }else if(cmd=="check"){
            cin >> tmp;
            if(s[tmp]) cout << 1<<'\n';
            else cout<< 0 <<'\n';
        }else if(cmd=="toggle"){
            cin >> tmp;
            if(s[tmp]) s[tmp]=false;
            else s[tmp]=true;
        }else if(cmd=="all"){
            for(i=1;i<=20;i++) s[i]=true;
        }else if(cmd=="empty"){
            for(i=1;i<=20;i++) s[i]=false;
        }
    }
}