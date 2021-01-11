#include <string>
#include <vector>

using namespace std;
int arr[100001]={0,1,1};
int solution(int n) {
    int answer = 0;
    for(int i=3;i<=n;i++){
        arr[i] = (arr[i-1]%1234567 + arr[i-2]%1234567)%1234567;
    }
    return answer=arr[n];
}