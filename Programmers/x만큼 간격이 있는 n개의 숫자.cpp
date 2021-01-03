#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    for(int i=1;i<=n;i++){
        long long tmp = x*i;
        answer.push_back(tmp);
    }
    return answer;
}