#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2,0);
    char last = words[0][0];
    map<string, int> m;

    for(int i=1;i<=words.size();i++){
        string word = words[i-1];
        if(m[word]==1||last!=word[0]){
            answer[1]=ceil((double)i/n);
            answer[0]=i%n==0?n:i%n;
            return answer;
        }else{
            last  = word[word.size()-1];
            m[word]++;
        }
    }
    return answer;
}