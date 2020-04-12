/*
백준 18111번 : 마인크래프트
https://www.acmicpc.net/problem/18111
*/
#include<iostream>
#include<vector>
#define MAX 210000000   
using namespace std;
int n,m,b;
vector<int> v;
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int i,max=0,min=MAX,ans,least = MAX;
    cin >> n>>m>>b;
    //완전탐색으로 구현하는데,최소 층수와, 최대 층수를 구한다음, 그 사이의 모든 층수를 만들어 보면서 문제를 해결했다.
    //먼저 층수 정보를 저장하면서, 최소층과 최대층을 찾는다.
    for(i=1;i<=n*m;i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        if(max < tmp) max = tmp;  
        if(min > tmp) min = tmp;
    }
    //층을 만들어 보는 반복문, 최소층에서 최대층까지만 반복한다.
    for(i=min;i<=max;i++){
        //층을 만드는데 사용된 블록의 수와 파괴된 블록의 수를 세는 변수
        int block=0,dest=0;
        for(int h : v){     //모든 층수를 확인하면서 만든다.
            if (h > i) {    //목표 층수가 저장된 층수보다 작은경우
				dest += h-i;    //목표 층수까지 저장된 층수를 부순다.
			}
			else if (h < i) {   //목표 층수가 저장된 층수보다 작은경우
				block -= h-i;   //block을 사용해서 층을 쌓아 올린다.
			}
        }
        //만약 파괴된 블록과 내가 가지고 있는 블록의 수의 합이 사용한 블록의 수보다 작다면 이는 만들수 없는 층이다.
        if (dest + b >= block) {
			int time = dest * 2 + block;
			if (least >= time) {
				least = time;
				ans = i;
			}
		}
    }
    cout << least << ' '<<ans;
}