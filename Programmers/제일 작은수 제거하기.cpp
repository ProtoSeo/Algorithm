#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int idx = -1,min = 2147483647;
    if(arr.size() == 1){
        answer.push_back(-1);
        return answer;
    }
    for(int i=0;i<arr.size();i++){
        if(min > arr[i]){
            idx = i;
            min = arr[i];
        }
    }
    for(int i=0;i<arr.size();i++){
        if(i == idx) continue;
        answer.push_back(arr[i]);
    }
    return answer;
}