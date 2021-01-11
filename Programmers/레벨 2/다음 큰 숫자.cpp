#include <string>
#include <vector>

using namespace std;
int binaryCnt(int t){
    int cnt=0;
    while(t!=0){
        if(t&1 == 1) cnt++;
        t = t>>1;
    }
    return cnt;
}
int solution(int n) {
    int answer = binaryCnt(n);
    for(int i=n+1;i<=2000000;i++){
        if(answer == binaryCnt(i)) return i;
    }
}