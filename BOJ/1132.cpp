/*
문제
N개의 숫자가 주어진다. 이 숫자는 모두 자연수이고, 알파벳 A부터 J가 자리수를 대신해서 쓰여 있다. 
이 알파벳은 모두 한 자리를 의미한다. 그리고, 각 자리수는 정확하게 알파벳 하나이다. 
0으로 시작하는 숫자는 없다. 이때, 가능한 숫자의 합 중 최댓값을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. N은 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에는 각 숫자가 주어진다. 숫자의 길이는 최대 12이다.

적어도 한 알파벳은 숫자의 가장 처음에 주어지지 않는다.

출력
첫째 줄에 합의 최댓값을 출력한다.
*/
#include <iostream>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
long long ary[10];
bool chk[10];   //all false
bool desc(long long a, long long b){ return a > b; }    //내림차순으로 정렬하기 위해서 필요한 함수
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,i,j,len;
    long long res=0;
    cin >>n;
    for(i=0;i<n;i++){
        string tmp;
        cin >> tmp;
        len = tmp.length();
        for (j=1;j<=len;j++){
            if(j==1){   //첫자리에는 0이 올수없으므로 이를 chk함수를 통해서 0이 올수없음을 true로 표시한다.
                chk[(tmp[j-1]-'A')] = true;
            }
            ary[(tmp[j-1]-'A')] += pow(10,len-j);   //자릿수에 맞춰서 10의 제곱승을 더해준다.
        }
    }
    bool flag = false;  //이는 숫자가 9개이상인지(0이 필요한지 없는지를 확인하는)확인하는 bool형이다.
    for(i=0;i<10;i++){  //ary에 0이 있다면, 사용되지 않는다는 뜻이다.
        if(ary[i]==0){  
            flag = true;    //숫자가 9개가 이하임을 true로 표시하고 break한다.
            break;
        }
    }
    if(!flag){  //0이 있는경우(숫자가 10개 다 사용되는 경우)
        long long tmp = 10000000000000; 
        int idx = -1;
        for(i=0;i<10;i++){  //0으로 사용될수있는 숫자중에서 최솟값을 찾는다.
            if(!chk[i]&&tmp>ary[i]){
                tmp = ary[i];
                idx = i;
            }
        }
        ary[idx]=0; //0으로 사용될수있는 숫자중에서의 최솟값을 0으로 만든다.(어차피 0을 곱하면 0이 되므로)
    }
    sort(ary,ary+10,desc);  //그리고 내림차순으로 정렬해준다.
    for(i=9;i>0;i--){   //내림차순으로 정렬됬으므로 큰수부터 9를 곱하고, 그 다음수에는 8을 곱한값을 더하고 이런식으로 정답을 구한다.
        res += ary[9-i]*i;
    }
    cout << res;    //출력
}