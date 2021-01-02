#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++){
        if(arr[i]%divisor==0){
            answer.push_back(arr[i]);
        }
    }
    if(answer.size()==0) answer.push_back(-1);
    //sort를 뒤에서 하는 것이 좀 더 효율적일것 같다.
    return answer;
}