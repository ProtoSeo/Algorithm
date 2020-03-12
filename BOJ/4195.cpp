/*
문제
민혁이는 소셜 네트워크 사이트에서 친구를 만드는 것을 좋아하는 친구이다. 
우표를 모으는 취미가 있듯이, 민혁이는 소셜 네트워크 사이트에서 친구를 모으는 것이 취미이다.

어떤 사이트의 친구 관계가 생긴 순서대로 주어졌을 때, 두 사람의 친구 네트워크에 몇 명이 있는지 구하는 프로그램을 작성하시오.

친구 네트워크란 친구 관계만으로 이동할 수 있는 사이를 말한다.

입력
첫째 줄에 테스트 케이스의 개수가 주어진다. 각 테스트 케이스의 첫째 줄에는 친구 관계의 수 F가 주어지며, 이 값은 100,000을 넘지 않는다. 
다음 F개의 줄에는 친구 관계가 생긴 순서대로 주어진다. 친구 관계는 두 사용자의 아이디로 이루어져 있으며, 
알파벳 대문자 또는 소문자로만 이루어진 길이 20 이하의 문자열이다.

출력
친구 관계가 생길 때마다, 두 사람의 친구 네트워크에 몇 명이 있는지 구하는 프로그램을 작성하시오.
*/
#include <iostream>
#include <map>
#include <string.h>
#include<string>
using namespace std;

int ary[100001];
map<string,int> m;
int find(int n) {   //파인드  
	if (ary[n] < 0) return n;
	return ary[n] = find(ary[n]);
}

void merge(int a, int b) {  //유니온
	a = find(a);
	b = find(b);
	if (a == b) return;
	ary[a] += ary[b];
	ary[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >>tc;
    while(tc--){
        memset(ary,-1,sizeof(ary));
        m.clear();
        int f,i,cnt=1;  //문자열을 입력받는데, 해당 문자열을 숫자로 매칭시켜주기 위한 cnt
        cin >> f;
        for(i=0;i<f;i++){   
            string id1,id2;
            cin >> id1>>id2;    
            //map에 해당하는 문자열이 없다면 새로운 문자열을 입력받은 것이므로 cnt를 증가시켜주고 맵에 넣는다.
            if(m[id1]==0) m[id1]=cnt++;
            if(m[id2]==0) m[id2]=cnt++;            
            
            int parent1 = find(m[id1]);
            int parent2 = find(m[id2]);
            if(parent1 != parent2)  //서로의 root가 다르면 union해준다.
                merge(parent1,parent2);
            cout<<-ary[parent1]<<'\n';  //root에서 음수로 해당 disjoint-set의 크기를 담고있으므로 음수로 출력해준다.
        }
    }
}