#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int,int> left={4,1}, right={4,3};
    vector<pair<int,int>> save;
    
    save.push_back({4,2});
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++) save.push_back({i,j});
    }
    
    for(int i=0;i<numbers.size();i++){
        int y = save[numbers[i]].first;
        int x = save[numbers[i]].second;
        if(numbers[i]==1||numbers[i]==4||numbers[i]==7){
            answer += "L";
            left = {y,x};
        }else if(numbers[i]==3||numbers[i]==6||numbers[i]==9){
            answer += "R";
            right = {y,x};
        }else {
            int leftLen = abs(left.first - y)+abs(left.second - x);
            int rightLen = abs(right.first - y)+abs(right.second - x);
            if(leftLen == rightLen){
                if(hand == "right"){
                    answer +="R";
                    right = {y,x};
                }else{
                    answer +="L";
                    left = {y,x};
                }
            }else if(leftLen > rightLen){
                answer +="R";
                right = {y,x};
            }else if(leftLen < rightLen){
                answer +="L";
                left = {y,x};
            }
        }
    }
    return answer;
}