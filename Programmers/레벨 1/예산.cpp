#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    sort(d.begin(),d.end());
    for(;d[answer]<=budget&&answer<d.size();answer++){
        budget -= d[answer];
    }
    return answer;
}