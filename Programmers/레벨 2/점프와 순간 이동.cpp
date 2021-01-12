#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    for(int i=n;i>0;){
        if(i%2==0){
            i/=2;
        }else{
            ans += 1;
            i-=1;
        }
    }
    return ans;
}