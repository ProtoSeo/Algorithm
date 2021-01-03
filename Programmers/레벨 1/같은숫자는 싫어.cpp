#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> s;
    for(int i=0;i<arr.size();i++){
        if(s.size()>0 && s.top()==arr[i]){
            continue;
        }
        s.push(arr[i]);
    }
    int size = s.size();
    for(int i=0;i<size;i++){
        answer.push_back(s.top());
        s.pop();
    }
    reverse(answer.begin(),answer.end());
    return answer;
}
//다른 분의 풀이를 봤는데, unique함수를 사용할 수도 있다는 것을 알게 되었다.