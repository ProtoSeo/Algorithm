#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(int a,int b){
    string na = to_string(a);
    string nb = to_string(b);
    return na+nb > nb+na;    
}
string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(),numbers.end(),cmp);
    for(int i :numbers) answer += to_string(i);
    
    if(answer[0]=='0') return "0";
    return answer;
}