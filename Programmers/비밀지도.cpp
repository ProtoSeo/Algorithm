#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0;i<n;i++){
        string result = "";
        int tmp = arr1[i]|arr2[i];
        for(int j=n-1;j>=0;j--){
            if((tmp & (int)pow(2,j)) == pow(2,j)){
                result += "#";
            }else{
                result += " ";
            }
        }
        answer.push_back(result);
    }
    
    return answer;
}