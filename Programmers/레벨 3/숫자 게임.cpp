#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0,i=0,j=0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    while(i<A.size()&&j<B.size()){
        if(A[i]<B[j]){
            i++,j++;
            answer++;
        }else{
            j++;
        }
    }
    return answer;
}