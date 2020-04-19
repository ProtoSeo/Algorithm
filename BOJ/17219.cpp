/*
백준 17219번 : 비밀번호 찾기
https://www.acmicpc.net/problem/17219
*/
#include<iostream>
#include<unordered_map>

using namespace std;
//map을 저장하는 용도로만 사용한다면 굳이 map을 사용하기 보다는 unordered_map을 사용해서 속도를 빠르게 하는편이 좋은것 같다.
unordered_map<string,string> password;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n>>m;
    while(n--){     //입력을 받아서 map에 저장한다.
        string s,pw;
        cin >> s >> pw;
        password[s] = pw;
    }
    while(m--){
        string s;   //찾고싶은 pw의 키를 입력받아서 찾아서 출력한다.
        cin >>s;
        cout << password[s]<<'\n';
    }
}