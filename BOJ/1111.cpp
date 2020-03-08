/*
문제
IQ Test의 문제 중에는 공통된 패턴을 찾는 문제가 있다. 수열이 주어졌을 때, 다음 수를 찾는 문제이다.

예를 들어, 1, 2, 3, 4, 5가 주어졌다. 다음 수는 무엇인가? 당연히 답은 6이다. 약간 더 어려운 문제를 보면, 3, 6, 12, 24, 48이 주어졌을 때, 다음 수는 무엇인가? 역시 답은 96이다.

이제 제일 어려운 문제를 보자.

1, 4, 13, 40이 주어졌을 때, 다음 수는 무엇일까? 답은 121이다. 그 이유는 항상 다음 수는 앞 수*3+1이기 때문이다.

은진이는 위의 3문제를 모두 풀지 못했으므로, 자동으로 풀어주는 프로그램을 작성하기로 했다. 항상 모든 답은 구하는 규칙은 앞 수*a + b이다. 그리고, a와 b는 정수이다.

수 N개가 주어졌을 때, 규칙에 맞는 다음 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. N은 50보다 작거나 같은 자연수이다. 둘째 줄에는 N개의 수가 주어진다. 이 수는 모두 절댓값이 100보다 작거나 같은 정수이다.

출력
다음 수를 출력한다. 만약 다음 수가 여러 개일 경우에는 A를 출력하고, 다음 수를 구할 수 없는 경우에는 B를 출력한다.
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    int i,n;
    cin >>n;
    vector<int> ary(n);
    for(i=0;i<n;i++) cin >>ary[i];
    if(n==1){   //수열의 길이가 1인경우 경우의 수가 많다.
        cout << "A";
    }else if(n==2){     //수열의 길이가 2인경우 에는 입력받은 수열이 2개가 같은 경우 또는 다른경우가 있다.
        if(ary[0]==ary[1]){
            cout << ary[0];
        }else{      //입력받은 수열이 서로 다른경우에는 경우의 수가 많다.
            cout << "A";
        }
    }else if (n>=3){
        int a,b,tmp1,tmp2;      //기울기와 계수를 구하기 위한 변수
        if(ary[0]!=ary[1]){
            tmp1 = ary[1]-ary[0];
            tmp2 = ary[2]-ary[1];
            a = tmp2/tmp1;  //기울기를 구하기 위함
            b = ary[1] - ary[0]*a;  //계수를 구하기 위함
            bool check = true;
            for(i=0;i<n-1;i++){     //해당 식에서 올바른 기울기와 계수를 구했는지 반복문을 통해 확인한다.
                if(a*ary[i]+b!=ary[i+1]){
                    check = false;
                    break;
                }
            }
            if(check){
                cout << a*ary[n-1] + b;
            }else{
                cout << "B";
            }
        }else{
            bool check = true;
            for(i=0;i<n-1;i++){     //해당 반복문은 모든 수열의 값이 같은 경우를 검사해주는 반복문이다.
                if(ary[i]!=ary[i+1]) {
                    check = false;
                    break;
                }
            }
            if(check)
                cout<<ary[0];
            else
                cout << "B";
        }
    }
}