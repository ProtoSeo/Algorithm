#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    while(a!=b){
        answer++;
        if(a%2==1) a+=1;
        if(b%2==1) b+=1;
        if(a==b) return answer;
        a/=2;
        b/=2;
    }
    return answer;
}