#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stk;
    for(int i=0;i<s.size();i++){
        if(stk.empty()){
            stk.push(s[i]);
        }else{
            if(stk.top()=='('&&s[i]==')'){
                stk.pop();
            }else{
                stk.push(s[i]);
            }
        }
    }
    
    return stk.empty();
}