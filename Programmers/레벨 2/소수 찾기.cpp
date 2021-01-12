#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

set<int> save;

bool isPrime(int number){
    if(number<=1) return false;
    for (int i = 2; i*i <= number; i++) { 
        if (number % i == 0) return false; 
    }
    return true;
}

void permutation(vector<bool> v,string numbers,string s,int lmt){
    if(s.size()==lmt){
        cout << stoi(s) <<' ';
        save.insert(stoi(s));
        return ;
    }
    for(int i=0;i<numbers.size();i++){
        if(v[i]){
            v[i] = false;
            permutation(v,numbers,s+numbers[i],lmt);
            v[i] = true;
        }
    }
}
int solution(string numbers) {
    int answer = 0;
    for(int i=1;i<=numbers.size();i++){
        vector<bool> visited(numbers.size()+1,1);
        permutation(visited,numbers,"",i);
    }
    for(auto it=save.begin();it!=save.end();++it){
        if(isPrime(*it)) answer++;
    }
    return answer;
}