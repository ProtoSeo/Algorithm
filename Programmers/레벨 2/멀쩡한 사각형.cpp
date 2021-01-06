#include<iostream>
#include <cmath>
using namespace std;

long long solution(int w,int h) {
    long long answer = (long long)w*h;
    int threshold = 0;
    for(long long i=1;i<=w;i++){
        int chk = floor(i*h/(double)w);
        if(chk==threshold){
            answer --;
        }else if(chk>threshold){
            answer -= (long long)(ceil(i*h/(double)w) - threshold);
            threshold = chk;
        }
    }
    return answer;
}