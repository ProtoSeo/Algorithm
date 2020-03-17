/*
문제
홍준이는 프로그래밍 대회를 개최했다. 이 대회는 사람들이 팀을 이루어서 참가해야 하며, 팀원의 수는 홍준이가 정해준다. 
팀원이 홍준이가 정한 값보다 부족하다면, 그 팀은 대회에 참여할 수 없다. 모든 팀은 같은 수의 팀원으로 이루어져 있다.

대회에 참여 의사를 밝힌 학교는 총 N개이다. 각 학교는 모든 학생이 참여할 수 있는 경우에만 대회에 참가한다. 
즉, 남는 사람 없이 모든 학생이 팀에 들어갈 수 있어야 한다.

대회는 예선과 본선으로 구성되어 있다. 모든 팀은 같은 학교 소속으로 이루어져 있어야 한다. 
예선에서 각 학교 1등팀만 본선에 진출한다. 

홍준이의 대회는 올해가 첫 해이기 때문에, 많은 관심이 필요하다. 따라서, 본선에 참가하는 사람의 수를 최대가 되도록 팀원의 수를 정하려고 한다. 
또, 본선이 지루해지는 것을 막기 위해 적어도 두 팀이 본선에 참가할 수 있어야 한다.

홍준이가 팀원을 몇 명으로 정해야 본선에 참가하는 사람의 수가 최대가 되는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 홍준이의 대회에 참여 의사를 밝힌 학교의 수 N (2 ≤ N ≤ 200,000)이 주어진다.
둘째 줄에는 각 학교 학생의 수가 주어진다. 학생의 수는 구간 [1, 2,000,000]에 포함된다.

출력
첫째 줄에 홍준이의 대회 본선에 참가하는 사람의 수의 최댓값을 출력한다.
*/
#include<iostream>
#define ll long long
using namespace std;
// map<ll,ll> res;  처음에 맵을 이용해서 문제를 풀었는데, TLE가 나왔다.
ll res[2000001];
void div(int num){  // 입력받은 num의 약수를 구하는 함수, 약수를 구한 뒤 배열을 이용해서 해당 약수의 수를 센다.
    for(int i=1;i*i<=num;i++){  
        if(num%i==0){
            res[i]++;   
            if(i != num/i){ 
                res[num/i]++;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n,i,tmp;
    ll max=0;
    cin >>n;    //학교수 입력
    for(i=0;i<n;i++){   
        cin >> tmp;     //학교의 수만큼 반복문을 돌리고 해당하는 반복문 만큼 학생수를 입력받는다.
        div(tmp);   //학생의 수를 입력받으면 해당하는 수의 약수를 구한다.
    }
    for(i=1;i<=2000000;i++){    //해당하는 배열의 크기만큼 반복문을 돌린다.
        if(res[i]>=2){  //그리고 약수의 개수가 2개 이상이라는것은 2개이상의 학교가 참가할수 있다는 것이다.
            if(res[i]*i>max){   //그리고 참가가능한 학생의 최대수는 약수의 수(참가하는 학교의 수) * 해당 약수 이다
                max =res[i]*i;  //이에 해당하는 값이 최댓값을 구해서 저장한다.
            }
        }
    }
    cout <<max;
}