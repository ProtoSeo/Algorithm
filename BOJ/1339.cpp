/*
문제
민식이는 수학학원에서 단어 수학 문제를 푸는 숙제를 받았다.

단어 수학 문제는 N개의 단어로 이루어져 있으며, 각 단어는 알파벳 대문자로만 이루어져 있다. 
이때, 각 알파벳 대문자를 0부터 9까지의 숫자 중 하나로 바꿔서 N개의 수를 합하는 문제이다. 
같은 알파벳은 같은 숫자로 바꿔야 하며, 두 개 이상의 알파벳이 같은 숫자로 바뀌어지면 안 된다.

예를 들어, GCF + ACDEB를 계산한다고 할 때, A = 9, B = 4, C = 8, D = 6, E = 5, F = 3, G = 7로 결정한다면, 
두 수의 합은 99437이 되어서 최대가 될 것이다.

N개의 단어가 주어졌을 때, 그 수의 합을 최대로 만드는 프로그램을 작성하시오.

입력
첫째 줄에 단어의 개수 N(1 ≤ N ≤ 10)이 주어진다. 둘째 줄부터 N개의 줄에 단어가 한 줄에 하나씩 주어진다. 
단어는 알파벳 대문자로만 이루어져있다. 모든 단어에 포함되어 있는 알파벳은 최대 10개이고, 수의 최대 길이는 8이다. 
서로 다른 문자는 서로 다른 숫자를 나타낸다.

출력
첫째 줄에 주어진 단어의 합의 최댓값을 출력한다.
*/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
int ary[26];
bool desc(int a, int b){ return a > b; }

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int t,i,ans=0;
    cin >>t;
    while(t--){
        //알파벳을 하나의 숫자 변수로 생각하고 10의 제곱수를 먼저 파악한다.
        string s;
        cin >>s;
        for(i=0;i<s.length();i++){  //길이 만큼 10의 제곱수로 저장한다.
            ary[s[i]-'A']+= pow(10,s.length()-i-1);
        }
    }
    sort(ary,ary+26,desc);  //내림차순으로 정렬을 한다.
    //반복문을 통해서 큰수부터 9에 매칭하고 이를 내려가면서 매칭한다.
    //그렇게 구현하면 가장 큰수를 구할수 있다.
    for(i=9;i>=0;i--) ans+=ary[9-i]*i;
    cout <<ans;
}