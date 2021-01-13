#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> result;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        result.push_back(temp);
    }
 
    return result;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    for(string r: record){
        vector<string>  result = split(r,' ');
        string tmp = result[1];
        if(result[0]=="Enter"){
            m[result[1]] = result[2];
            tmp +="-님이 들어왔습니다.";
            answer.push_back(tmp);
        }
        else if(result[0]=="Leave"){
            tmp +="-님이 나갔습니다.";
            answer.push_back(tmp);
        }
        else if(result[0]=="Change"){
            m[result[1]] = result[2];
        }
    }
    for(int i=0;i<answer.size();i++){
        vector<string> result = split(answer[i],'-');
        answer[i] = m[result[0]]+result[1];
    }
    return answer;
}