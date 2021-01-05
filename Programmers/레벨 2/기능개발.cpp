#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int idx = 0,size = progresses.size();
    while(idx<size){
        for(int i=idx;i<size;i++) progresses[i] += speeds[i];
        
        if(progresses[idx]>=100){
            int tmp=idx+1;
            for(;tmp<size;tmp++){
                if(progresses[tmp] < 100) break;
            }
            answer.push_back(tmp-idx);
            idx = tmp;
        }
    }
    return answer;
}