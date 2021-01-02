#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int pcnt = 0,ycnt =0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='y'||s[i]=='Y'){
            ycnt++;
        }else if(s[i]=='p'||s[i]=='P'){
            pcnt++;
        }
    }
    return (ycnt==pcnt)? true:false;
}