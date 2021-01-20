#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(),0);
    stack<int> stk;
    for(int i=0;i<prices.size();i++){
        if(stk.empty()){
            stk.push(i);
        }else{
            if(prices[stk.top()]<=prices[i]){
                stk.push(i);
            }else{
                vector<int> save;
                while(!stk.empty()&&prices[stk.top()]>prices[i]){
                    save.push_back(stk.top());
                    stk.pop();
                }
                stk.push(i);
                for(int idx : save) answer[idx] = i - idx;   
            }
        }
    }
    while(!stk.empty()){
        answer[stk.top()] = prices.size()-1-stk.top();
        stk.pop();
    }
    
    return answer;
}