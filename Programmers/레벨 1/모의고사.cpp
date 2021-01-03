#include <string>
#include <vector>
// #include<algorithm>
#include<iostream>

using namespace std;
int a[] = {1,2,3,4,5};
int b[] = {2,1,2,3,2,4,2,5};
int c[] = {3,3,1,1,2,2,4,4,5,5};
vector<int> solution(vector<int> answers) {
    vector<int> answer; 
    int result[] = {0,0,0};
    // vector<int> result(3);
    for(int i=0;i<answers.size();i++){
        if(a[i%5]==answers[i]){
            result[0]++;
        }
        if(b[i%8]==answers[i]){
            result[1]++;
        }
        if(c[i%10]==answers[i]){
            result[2]++;
        }
    }
    int max = -1;
    // int max = *max_element(result.begin(),result.end());
    for(int i=0;i<3;i++){
        if(result[i]>max){
            max = result[i];
        }
    }
    
    for(int i=0;i<3;i++){
        if(result[i]==max){
            answer.push_back(i+1);
        }
    }
    return answer;
    
}