#include <string>
#include <vector>
#include <iostream>
using namespace std;
int d[100001];
int solution(int n, vector<int> money) {
    d[0] = 1;
    for(int m : money){
        for(int i = 1;i<=n;i++){
            if(i>=m){
                d[i] += d[i-m];
            }
        }
    }
    return d[n];
}