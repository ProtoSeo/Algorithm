/*
문제
N개의 선분들이 2차원 평면상에 주어져 있다. 선분은 양 끝점의 x, y 좌표로 표현이 된다.

두 선분이 서로 만나는 경우에, 두 선분은 같은 그룹에 속한다고 정의하며, 그룹의 크기는 그 그룹에 속한 선분의 개수로 정의한다. 
두 선분이 만난다는 것은 선분의 끝점을 스치듯이 만나는 경우도 포함하는 것으로 한다.

N개의 선분들이 주어졌을 때, 이 선분들은 총 몇 개의 그룹으로 되어 있을까? 또, 가장 크기가 큰 그룹에 속한 선분의 개수는 몇 개일까? 
이 두 가지를 구하는 프로그램을 작성해 보자.

입력
첫째 줄에 N(1≤N≤3,000)이 주어진다. 둘째 줄부터 N+1번째 줄에는 양 끝점의 좌표가 x1, y1, x2, y2의 순서로 주어진다. 
각 좌표의 절댓값은 5,000을 넘지 않으며, 입력되는 좌표 사이에는 빈칸이 하나 이상 있다.

출력
첫째 줄에 그룹의 수를, 둘째 줄에 가장 크기가 큰 그룹에 속한 선분의 개수를 출력한다.
*/
#include<iostream>
#include<set>
#include<string.h>
#define x first
#define y second
using namespace std;
int ary[3001];
pair<pair<int,int>,pair<int,int>> line[3001];
//union-find
int find(int n) {
	if (ary[n] < 0) return n;
	return ary[n] = find(ary[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	ary[a] += ary[b];
	ary[b] = a;
}

int ccw(pair<int,int> a,pair<int,int> b , pair<int,int> c){ //ccw알고리즘
    int tmp = a.x*b.y + b.x*c.y + c.x*a.y;
    tmp = tmp - a.y*b.x - b.y*c.x - c.y*a.x; 
    if(tmp >0){
        return 1;
    }else if(tmp<0){
        return -1;
    }else{  
        return 0;
    }
}

bool intersection(pair<int,int> A,pair<int,int> B,pair<int,int> C,pair<int,int> D){
    int AB = ccw(A,B,C) * ccw(A,B,D);   //AB직선에서 C좌표와 D좌표를 바라보았을때의 값
    int CD = ccw(C,D,A) * ccw(C,D,B);   //CD직선에서 A좌표와 B좌표를 바라보았을때의 값
    if(AB==0&&CD==0){   //두 직선이 일직선인 경우 A-B C-D인 경우 or A-C-B-D이런 경우 판단하는 조건문
        //위의 조건대로 정렬되는지 확인하기위해서 좌표상에서의 최대값 최소값을 찾아서 swap한다.
        if(A>B)swap(A,B);    
        if(C>D)swap(C,D);
        return C <= B&&A <= D;
    }
    return AB <=0 && CD <= 0 ;  //십자모양인지 확인한다.(그림을 그려보면 쉽게 이해 가능)
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int i,j,n;
    memset(ary,-1,sizeof(ary));     //유니온파인드 알고리즘을 위해서 배열을 -1로 초기화
    set<int> res;
    cin >>n;
    for(i=1;i<=n;i++){  //line vector에 한 선분을 이루는 점들을 저장한다.
        cin >> line[i].first.x >> line[i].first.y >> line[i].second.x >> line[i].second.y;
    }
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){    //모든 점들을 interaction함수를 통해서 겹치는 점이 있는지 확인한다.
            if(intersection(line[i].first,line[i].second,line[j].first,line[j].second)==1){ 
                merge(i,j); //만약 겹치는 부분이 있다면 한 선분그룹으로 만들기 위해서 merge한다.
            }
        }
    }
    for(i=1;i<=n;i++){  //find함수를 통해서 root값만 찾아서 set에 넣는다(set을 통해서 중복되는 요소를 없앤다.)
        res.insert(find(i));
    }
    int max=0;
    for(int it : res){  //set에 저장된 root의 인덱스를 가지고 저장되어있는 그룹의 값을 출력한다.
        if(max<-ary[it]){
            max = -ary[it];
        }
    }
    cout << res.size() <<'\n'<<max; 
}