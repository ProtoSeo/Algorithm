/*
백준 9019번 : DSLR
https://www.acmicpc.net/problem/9019
*/
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;
    cin >>t;
    while(t--){
        int s,e;
        pair<int,char> visited[10001];  //방문을 검사하는 동시에, 어떤 명령으로 도착했는지를 저장하는 vector
        queue<int> q;
        cin >> s>>e;
        q.push(s);
        visited[s].second = '0';    //처음 명령은 '0'로 초기화
        while(!q.empty()){      //BFS로 구현
            int now = q.front();
            q.pop();
            if(now == e) break;     //현재의 위치가 종료되어야 하는 값과 같다면 break
            int tmp = (now * 2)%10000;  //D명령을 실행시켰을 때의 값이 비어있는지 확인
            if(visited[tmp].second=='\0'){  //비어있다면
                visited[tmp].first = now;   //해당 값에 현재 값을 넣고 명령을 저장
                visited[tmp].second='D';
                q.push(tmp);
            }
            tmp = (now-1 < 0)? 9999:now-1;  //D명령을 실행시켰을 때의 값이 비어있는지 확인
            if(visited[tmp].second =='\0'){ //비어있다면
                visited[tmp].first = now;   //해당 값에 현재 값을 넣고 명령을 저장
                visited[tmp].second='S';
                q.push(tmp);
            }
            tmp = (now % 1000) * 10 + now /1000;    //D명령을 실행시켰을 때의 값이 비어있는지 확인
            if(visited[tmp].second=='\0'){  //비어있다면
                visited[tmp].first = now;   //해당 값에 현재 값을 넣고 명령을 저장
                visited[tmp].second='L';
                q.push(tmp);
            }
            tmp = (now / 10) + (now %10)*1000;  //D명령을 실행시켰을 때의 값이 비어있는지 확인
            if(visited[tmp].second=='\0'){  //비어있다면 
                visited[tmp].first = now;   //해당 값에 현재 값을 넣고 명령을 저장
                visited[tmp].second='R';
                q.push(tmp);
            }
        }
        //종료가 되었다면 종료된 지점부터 거꾸로 찾아가면서 명령을 재조합 한다.
        string str="";
        for(int i=e;i!=s;){
            str += visited[i].second;
            i=visited[i].first;
        }
        //해당 명령은 지금 뒤에서부터 찾아졌으므로 명령을 뒤집어 줘야한다.
        reverse(str.begin(),str.end());
        cout <<str<<'\n';
    }
}