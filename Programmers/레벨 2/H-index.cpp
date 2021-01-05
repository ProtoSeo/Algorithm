#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end());
    for(int i=citations.size();i>0;i--){
        if(citations[citations.size()-i]>=i){
            return i;
        }
    }
    return answer;
}