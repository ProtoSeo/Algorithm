#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i=n;i>0;i--){
        int tmp =0;
        for(int j=i;j>0;j--){
            tmp += j;
            if(tmp ==n){
                answer++;
                break;
            }
            if(tmp>n){
                break;
            }
        }
    }
    return answer;
}