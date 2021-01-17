#include <string>
#include <vector>

using namespace std;
int dp[60001]= {0,1,2};
int solution(int n) {
    for(int i=3;i<=n;i++){
        dp[i] = (dp[i-1]%1000000007 + dp[i-2]%1000000007)%1000000007;
    }
    return dp[n];
}