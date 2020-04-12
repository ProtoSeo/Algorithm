/*
백준 18870번 : 좌표 압축
https://www.acmicpc.net/problem/18870
*/
#include<iostream>
#include<set>
#include<unordered_map>
using namespace std;
int ary[1000001];
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,i;
    cin >>n;
    set<int> s;
    unordered_map<int,int> m;
    //아이디어는 좌표를 0부터 순서를 맞춰서 다시 저장해주면 좌표 압축이 될 것이라고 생각함
    for(i=0;i<n;i++){   // ary에 좌표를 입력받아서 저장한다.
        cin >> ary[i];
        s.insert(ary[i]);   //좌표의 크기를 줄세우기 위한 set + 중복을 삭제함
    }
    i=0;  //set에 저장된 순서대로 크기를 다시 map에 줄세우기 위함
    for(int a : s) m[a] = i++;
    //map에 세워진 줄을 보고서 ary에 저장된 값을 map에 검색해서 이를 반환한다.
    for(i=0;i<n;i++) cout << m[ary[i]]<<' ';
}
