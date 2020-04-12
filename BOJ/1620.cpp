/*
백준 1620번 : 나는야 포켓몬 마스터 이다솜
https://www.acmicpc.net/problem/1620
*/
#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int a,b,i=1;    
    //map을 이용할 수도 있다.
    //unordered_map이 더 빠르다.(정렬을 하는지 안하는지의 차이)
    unordered_map<int,string> m;
    unordered_map<string,int> k;
    cin >> a>>b;
    while(a--){     //입력
        string s;
        cin >>s;
        m[i]=s;     //m map에는 순서를 key로 몬스터의 이름을 저장한다.
        k[s]=i;     //s map에는 몬스터의 이름을 key로 순서를 저장한다.
        i++;
    }
    while(b--){ //명령의 수만큼 반복한다.
        string s;
        cin >> s;
        if('A'<=s[0]&&s[0]<='Z'){   //알파벳이 입력받았다면, 몬스터의 이름이 입력받은 것이므로 k map에서 검색해서 번호를 찾는다.
            cout<<k[s]<<'\n';
        }else{  //첫글자가 알파벳이 아니라면 숫자를 입력받은 것이다.
            int t = stoi(s);    //stoi를 이용해서 int형으로 바꾼다.
            cout << m[t]<<'\n'; //그리고 번호를 입력받은 것이므로 m map을 이용해서 몬스터의 이름을 검색한다.
        }
    }
}