#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
string conversion(string s){
    string result = "";
    for(int i=0;i<s.size();i++){
        if('a'<=s[i]&&s[i]<='z'){
            result += s[i]-('a'-'A');
        }else if('A'<=s[i]&&s[i]<='Z'){
            result += s[i];
        }else {
            result+=' ';
        }
    }
    return result;
}

int solution(string str1, string str2) {
    int answer = 0;
    str1 = conversion(str1);
    str2 = conversion(str2);
    int uni = 0, inter = 0;
    map<string,int> m1;
    map<string,int> m2;
    set<string> key;
    for(int i=0;i<str1.size()-1;i++){
        if(str1[i]!=' '&&str1[i+1]!=' '){
            string tmp = "";
            tmp += str1[i];
            tmp += str1[i+1];
            m1[tmp]++;
            key.insert(tmp);
        }
    }
    for(int i=0;i<str2.size()-1;i++){
        if(str2[i]!=' '&&str2[i+1]!=' '){
            string tmp = "";
            tmp += str2[i];
            tmp += str2[i+1];
            m2[tmp]++;
            key.insert(tmp);
        }
    }
    for(string k : key){
        uni += max(m1[k],m2[k]);
        inter += min(m1[k],m2[k]);
    }
    cout << uni <<' '<<inter;
    
    return (uni==0&&inter==0)?65536:(int)(65536*(double)inter/uni);
}