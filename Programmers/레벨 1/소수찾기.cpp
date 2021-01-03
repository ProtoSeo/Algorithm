#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> prime(n+1,true);
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i]){
            for (int j = i * i; j <= n; j += i) prime[j] = false;
        }
    }
     for (int i = 2; i <= n; i++)
    {
        if (prime[i]) answer++;
    }
    return answer;
}