#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    if(num == 1) return 0;
    for(int i=1;i<=500;i++){
        if(num%2==0){
            num /= 2;
        }else if(num%2==1){
            num = (num * 3) + 1;
        }
        if(num == 1) return i;
    }
    return -1;
}