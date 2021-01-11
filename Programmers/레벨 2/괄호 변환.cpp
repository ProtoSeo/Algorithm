#include <string>
#include <vector>
#include <stack>

using namespace std;
bool isCorrect(string s){
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
string separation(string s){
    if(s == ""||s==" ") return "";
    
    int left = 0,right=0;
    string u="",v="";
    for(int i=0;i<=s.size();){
        if(left==right&&left>0&&right>0){
            u = s.substr(0,i);
            v = s.substr(i);
            break;
        }else{
            if(s[i]=='('){
                left++;
            }else{
                right++;
            }
            i++;
        }
    }
    if(isCorrect(u)){
        return u + separation(v);
    }else{
        string tmp="(";
        tmp += separation(v) + ")";
        for(int i=1;i<u.size()-1;i++){
            if(u[i]=='(') tmp +=')';
            else tmp +='(';
        }
        return tmp;
    }
}
string solution(string p) {
    string answer = "";
    answer = separation(p);
    return answer;
}