#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(char a, char b){
    return a > b;
}
string solution(string s) {
    vector<char> v;
    string answer = "";
    for(int i=0;i<s.size();i++) v.push_back(s[i]);
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<s.size();i++) answer += v[i];
    return answer;
}