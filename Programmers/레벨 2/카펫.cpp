#include <string>
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int> candidate;
    int tmp = brown + yellow;
    for(int i=3;i<=tmp/3;i++){
        if(tmp% i ==0) candidate.push_back(i);
    }
    for(int w : candidate) {
        int h = tmp/w;
        if(yellow == (w-2)*(h-2) && brown == (w*h)-yellow){
            return {max(w,h),min(w,h)};
        }
    }
    return answer;
}