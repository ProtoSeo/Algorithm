#include <string>
#include <vector>
#include<iostream>
using namespace std;

string solution(vector<string> seoul) {
    for(int i=0;i<seoul.size();i++){
        if(seoul[i] == "Kim"){
            return "김서방은 "+ to_string(i)+"에 있다";
        }
    }
}