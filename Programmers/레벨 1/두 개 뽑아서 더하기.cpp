#include <string>
#include <vector>
#include<iostream>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> s;
    for(int i=0;i<numbers.size();i++){
        for(int j=i+1;j<numbers.size();j++){
            s.insert(numbers[i]+numbers[j]);
        }
    }
    for(auto it = s.begin();it!=s.end();++it){
        answer.push_back(*it);
    }
    return answer;
}