#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            if((n/i)==i){
                answer +=i;
            }else{
                answer += ((n/i) + i);    
            }
        }
    }
    return answer;
}