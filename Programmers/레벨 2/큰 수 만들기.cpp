#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    for(int i=0;i<number.size()&&k!=0;i++){
        if(number[i]<number[i+1]){
            number.erase(i,1);
            i=-1;
            k--;
        }
    }
    if(k>0) number = number.substr(0,number.size()-k);
    return number;
}