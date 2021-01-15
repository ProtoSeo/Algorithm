#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int result = 0,t_copy=0;
vector<int> num_copy;
void DFS(int tmp,int m, int k,int cnt){
    if(cnt == m){
        if(tmp==t_copy) result++;
        return;
    }
    DFS(tmp+num_copy[k],m,k+1,cnt+1);
    DFS(tmp-num_copy[k],m,k+1,cnt+1);
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    num_copy = numbers;
    t_copy = target;
    DFS(0,numbers.size(),0,0);
    
    return result;
}