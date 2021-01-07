#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool word = false;
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            word = false;
            continue;
        }else {
            if(!word){
                word = true;
                if('a'<=s[i]&&s[i]<='z'){
                    s[i] -= ('a' - 'A');   
                } 
            }else {
                if(word&&'A'<=s[i]&&s[i]<='Z'){
                    s[i] += ('a' - 'A'); 
                }
            }
        }
    }
    return s;
}