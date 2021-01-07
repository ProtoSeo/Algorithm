#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(string a, string b){
    string a_head="",b_head="",a_num="",b_num="";
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            for(int j=i;j<a.size();j++){
                if(a[j]>='0'&&a[j]<='9') a_num += a[j];
                else break;
            }
            break;
        }else{
            a_head+=a[i];
        }
    }
    for(int i=0;i<b.size();i++){
        if(b[i]>='0'&&b[i]<='9'){
            for(int j=i;j<b.size();j++){
                if(b[j]>='0'&&b[j]<='9') b_num += b[j];
                else break;
            }
            break;
        }else{
            b_head+=b[i];
        }
    }
    for(int i=0;i<a_head.size();i++){
        if(a_head[i]>='A'&&a_head[i]<='Z') a_head[i] += 'a'-'A';
    }
    for(int i=0;i<b_head.size();i++){
        if(b_head[i]>='A'&&b_head[i]<='Z') b_head[i] += 'a'-'A';
    }
    if(a_head==b_head) return stoi(a_num)<stoi(b_num);
    return a_head<b_head;
}
vector<string> solution(vector<string> files) {
    stable_sort(files.begin(),files.end(),cmp);
    return files;
}