/*
문제
접미사 배열은 문자열 S의 모든 접미사를 사전순으로 정렬해 놓은 배열이다.

baekjoon의 접미사는 baekjoon, aekjoon, ekjoon, kjoon, joon, oon, on, n 으로 총 8가지가 있고, 
이를 사전순으로 정렬하면, aekjoon, baekjoon, ekjoon, joon, kjoon, n, on, oon이 된다.

문자열 S가 주어졌을 때, 모든 접미사를 사전순으로 정렬한 다음 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 문자열 S가 주어진다. S는 알파벳 소문자로만 이루어져 있고, 길이는 1,000보다 작거나 같다.

출력
첫째 줄부터 S의 접미사를 사전순으로 한 줄에 하나씩 출력한다.
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string str;
    vector<string> vec;
    cin >> str; //입력
    for(int i=0;i<str.length();i++){    //str의 길이만큼 반복문을 반복    
        string tmp = str; 
        tmp.erase(0,i); //str을 뒤에서부터 1씩 잘라서
        vec.push_back(tmp);     //이를 vector에 저장한다.
    }  
    sort(vec.begin(),vec.end());    //vector를 정렬함으로서 문자열 순서대로 정렬한다.
    for(int i=0;i<vec.size();i++){
        cout<< vec[i]<<'\n';
    }
}