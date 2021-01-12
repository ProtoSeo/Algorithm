#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <cmath>

using namespace std;
string str_copy = "";
long long result = 0;
void permutation(vector<bool> v,string s,string exp){
    if(s.size()==str_copy.size()){
        vector<long long> num;
        vector<char> cal;
        string tmp = "";
        for(char c: exp){
            if('0'<=c&&c<='9'){
                tmp +=c;
            }else{
                if(c=='*'||c=='-'||c=='+') cal.push_back(c);
                num.push_back(stol(tmp));
                tmp ="";
            }
        }
        for(char c: s){
            vector<long long> num_tmp;
            vector<char> cal_tmp;
            num_tmp.push_back(num[0]);
            for(int i=0;i<cal.size();i++){
                int chk = num[i+1];
                if(cal[i]==c){
                    long long chk1 = num_tmp.back();
                    num_tmp.pop_back();
                    
                    if(c=='+'){
                        num_tmp.push_back(chk1+chk);
                    }else if(c=='*'){
                        num_tmp.push_back(chk1*chk); 
                    }else if(c=='-'){
                        num_tmp.push_back(chk1-chk);
                    }
                }else{
                    cal_tmp.push_back(cal[i]);
                    num_tmp.push_back(chk);
                }
            }
            num = num_tmp;
            cal = cal_tmp;
        }
        if(result<abs(num[0])) result = abs(num[0]); 
        return ;
    }
    for(int i=0;i<str_copy.size();i++){
        if(v[i]){
            v[i] = false;
            permutation(v,s+str_copy[i],exp);
            v[i]=true;
        }
    }
}
long long solution(string expression) {
    long long answer = 0;
    set<char> s;
    for(auto c: expression){
        if(c=='*'||c=='-'||c=='+') s.insert(c);
    }
    string str(s.begin(),s.end());
    str_copy = str;
    vector<bool> visited(str.size(),1);
    permutation(visited,"",expression+" ");
    return result;
}