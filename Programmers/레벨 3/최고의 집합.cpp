#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int t = s/n,a = s%n;
    if(t == 0) return {-1};
    
    for(int i=0;i<n;i++) answer.push_back(t);
    for(int i=n-1;i>=n-a;i--) answer[i]++;
    
    return answer;
}