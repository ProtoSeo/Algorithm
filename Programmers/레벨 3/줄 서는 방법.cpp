#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    long long tmp = 1,a=k-1;
    int m = n-1;
    for(int i=1;i<n;i++) tmp *= i;
    vector<bool> visited(n+1,1);
    while(answer.size()<n-1){
        int idx=1,cnt=0;
        int chk = (a / tmp)+1;
        a %= tmp;
        tmp/=m--;
        while(cnt!=chk){
            if(visited[idx]==true){
                cnt++;
                idx++;
            }else{
                idx++;
            }
        }
        visited[idx-1] = false;
        answer.push_back(idx-1);
    }
    for(int i=1;i<=n;i++){
        if(visited[i]==true){
            answer.push_back(i);
            break;
        }
    }

    return answer;
}