/*
문제
두 전봇대 A와 B 사이에 하나 둘씩 전깃줄을 추가하다 보니 전깃줄이 서로 교차하는 경우가 발생하였다. 
합선의 위험이 있어 이들 중 몇 개의 전깃줄을 없애 전깃줄이 교차하지 않도록 만들려고 한다.

예를 들어, <그림 1>과 같이 전깃줄이 연결되어 있는 경우 A의 1번 위치와 B의 8번 위치를 잇는 전깃줄, 
A의 3번 위치와 B의 9번 위치를 잇는 전깃줄, A의 4번 위치와 B의 1번 위치를 잇는 전깃줄을 없애면 남아있는 모든 전깃줄이 서로 교차하지 않게 된다. 



전깃줄이 전봇대에 연결되는 위치는 전봇대 위에서부터 차례대로 번호가 매겨진다. 
전깃줄의 개수와 전깃줄들이 두 전봇대에 연결되는 위치의 번호가 주어질 때, 
남아있는 모든 전깃줄이 서로 교차하지 않게 하기 위해 없애야 하는 최소 개수의 전깃줄을 구하는 프로그램을 작성하시오.

입력
첫째 줄에는 두 전봇대 사이의 전깃줄의 개수가 주어진다. 전깃줄의 개수는 100,000 이하의 자연수이다. 
둘째 줄부터 한 줄에 하나씩 전깃줄이 A전봇대와 연결되는 위치의 번호와 B전봇대와 연결되는 위치의 번호가 차례로 주어진다. 
위치의 번호는 500,000 이하의 자연수이고, 같은 위치에 두 개 이상의 전깃줄이 연결될 수 없다. 

출력
첫째 줄에 남아있는 모든 전깃줄이 서로 교차하지 않게 하기 위해 없애야 하는 전깃줄의 최소 개수를 출력한다. 
둘째 줄부터 한 줄에 하나씩 없애야 하는 전깃줄의 A전봇대에 연결되는 위치의 번호를 오름차순으로 출력한다. 
만약 답이 두 가지 이상이라면 그 중 하나를 출력한다.
*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
bool visit[500001];
vector<int> vt;
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n,i,max=0,cnt=0;
    cin >> n;
    vector<pair<int,int>> input;    //입력값을 입력받기 위한 vector
    vector<pair<int,int>> res;
    for(i=0;i<n;i++){   //입력값을 입력받는다.
        int x,y;
        cin >> x >> y;
        visit[x] = true;    //동시에 방문을 표시해주는 배열에 true로 표시한다.
        input.push_back({x,y}); 
    }
    sort(input.begin(),input.end());    //그리고 첫번째 전봇대를 기준으로 정렬을 해준다.
    vt.push_back(-2100000000);  
    for(i=0;i<n;i++){   //LIS O(nlogn) 알고리즘
        int x = input[i].second;
        if(vt.back()< x){
            vt.push_back(x);
            max++;
            res.push_back({input[i].first,max});
        }else{
            auto it = lower_bound(vt.begin(),vt.end(),x);
            *it = x;
            res.push_back({input[i].first,it-vt.begin()});
            cnt++;  //n번 반복하는데 여기서 max가 아닐때 호출되는 수는 n-max와 같다는 것이다.
        }
    }
    for(auto it = res.rbegin();it!=res.rend();it++){   //res에 저장된 순서를 뒤에서 부터 다시 확인한다.
        if(max == 0) break;
        else if(it->second == max){     //뒤에서 부터 확인했을때 max와 같다면
            visit[it->first] = false;   //해당 방문 배열에 false를 한다. 이렇게 되면 교차되어있는 전선만 true로 남아있을 것이다.
            max--;
        }
    }
    cout<< cnt<<'\n';   //cnt = n - max
    for(i=1;i<=500000;i++){
        if (visit[i]){  //방문배열의 인덱스를 통해서 정답 출력
            cout << i <<'\n';
            cnt--;
        }
        if (cnt == 0) break;
    }
}