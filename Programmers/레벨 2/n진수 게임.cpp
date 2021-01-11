#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char c[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
string solution(int n, int t, int m, int p) {
    string total = "0",answer="";
    for(int i=0;i<=m*t;i++){
        string tmp ="";
        int num = i;
        while(num>0){
            tmp += c[num%n];
            num/=n;
        }
        reverse(tmp.begin(),tmp.end());
        total += tmp;
    }
    for(int i=0;i<t;i++){
        answer += total[(p-1)+(i*m)];
    }
    return answer;
}