#include <vector>
#include <iostream>
using namespace std;

int result = 0;
bool isPrime(int number){
    if(number<=1) return false;
    for(int i=2;i*i<=number;i++){
        if(number % i ==0) return false;
    }
    return true;
}
void permutation(int cnt,vector<bool> v,vector<int>nums){
    if(cnt == 3){
        int tmp = 0;
        for(int i=0;i<v.size();i++){
            if(!v[i]) tmp += nums[i];
        }
        if(isPrime(tmp)) result++;
        return ;
    }
    for(int i=0;i<v.size();i++){
        if(v[i]){
            v[i] = false;
            permutation(cnt+1,v,nums);
            v[i] = true;
        }
    }
}
int solution(vector<int> nums) {
    int answer = 0;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    // vector<bool> visited(nums.size(),1);
    // permutation(0,visited,nums);
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            for(int k=j+1;k<nums.size();k++){
                int tmp = nums[i] + nums[j] + nums[k];
                if(isPrime(tmp)) answer ++;
            }
        }
    }
    return answer;
}