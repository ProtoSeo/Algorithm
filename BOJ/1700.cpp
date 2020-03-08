/*
문제
기숙사에서 살고 있는 준규는 한 개의 멀티탭을 이용하고 있다. 준규는 키보드, 헤어드라이기, 핸드폰 충전기, 디지털 카메라 충전기 등 여러 개의 전기용품을 사용하면서 어쩔 수 없이 각종 전기용품의 플러그를 뺐다 꽂았다 하는 불편함을 겪고 있다. 그래서 준규는 자신의 생활 패턴을 분석하여, 자기가 사용하고 있는 전기용품의 사용순서를 알아내었고, 이를 기반으로 플러그를 빼는 횟수를 최소화하는 방법을 고안하여 보다 쾌적한 생활환경을 만들려고 한다.

예를 들어 3 구(구멍이 세 개 달린) 멀티탭을 쓸 때, 전기용품의 사용 순서가 아래와 같이 주어진다면, 

1. 키보드
2. 헤어드라이기
3. 핸드폰 충전기
4. 디지털 카메라 충전기
5. 키보드
6. 헤어드라이기
키보드, 헤어드라이기, 핸드폰 충전기의 플러그를 순서대로 멀티탭에 꽂은 다음 디지털 카메라 충전기 플러그를 꽂기 전에 핸드폰충전기 플러그를 빼는 것이 최적일 것이므로 플러그는 한 번만 빼면 된다. 

입력
첫 줄에는 멀티탭 구멍의 개수 N (1 ≤ N ≤ 100)과 전기 용품의 총 사용횟수 K (1 ≤ K ≤ 100)가 정수로 주어진다. 두 번째 줄에는 전기용품의 이름이 K 이하의 자연수로 사용 순서대로 주어진다. 각 줄의 모든 정수 사이는 공백문자로 구분되어 있다. 

출력
하나씩 플러그를 빼는 최소의 횟수를 출력하시오. 
*/
#include<iostream>
#include<vector>
using namespace std;
int n,m;
int main() {
	ios::sync_with_stdio(false); 
    cin.tie(NULL);
	int t, i, j,k,chk=0,cnt=0;
	cin >> n>>m;
    vector<int> con(n,-1);
    vector<int> ary(m);
    for(i=0;i<m;i++) cin >> ary[i];
    //첫번째 플러그를 콘센트에 꽂는다.
    con[chk++] = ary[0];
    for(i=1;i<m;i++){
        // 콘센트를 다 사용하고 있지 않을 때
        if(chk!=n){
            bool flag = true;
            for(j=0;j<chk;j++){
                if(ary[i] == con[j]){
                    flag = false;
                    break;
                }
            }
            //만약 중복되는 플러그가 아니었다면 비어있는 콘센트에 플러그를 꽂아야한다.
            if(flag){
                con[chk++] = ary[i];
            }
        }
        else{   //콘센트를 다 사용하고 있어서 뽑아야 하는 경우
            vector<int> temp(n);    //어떤 플러그를 뽑아야 하는지에 대해서 뭐가 더 최대인지를 알려줄 vector(가중치 저장하는 느낌)
            bool overlap = false;
            for(j=0;j<n;j++){    //이전 콘센트에 ary[i]플러그가 꽂혀있는지 확인
                if(ary[i]==con[j]){
                    overlap = true;
                    break;
                }
            }
            if(!overlap){   //꽂혀있지 않을 때
                for(j=0;j<n;j++){    //어떤 콘센트를 뽑을지 결정하는 반복문
                    bool flag = false;  //뒤에 다시 사용하는지를 저장해줄 bool형 변수
                    for(k=i+1;k<m;k++){
                        if(con[j] == ary[k]){
                            flag = true;
                            temp[j] = k;
                            break;
                        }
                    }
                    if(!flag){
                        temp[j]+=m;     
                    }
                }
                int max = 0,num = -1;
                for(j=0;j<n;j++){   //최대값 위치를 파악하는 반복문
                    if(max<temp[j]) {
                        max = temp[j];
                        num = j;
                    } 
                }
                con[num] = ary[i];
                cnt++;
            }
        }
    }
    cout << cnt;
}