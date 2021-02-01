#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long cache[2001]={0,1,2};
    for(int i=3;i<=n;i++){
        cache[i] = (cache[i-1] + cache[i-2])%1234567;
    }
    return cache[n];
}