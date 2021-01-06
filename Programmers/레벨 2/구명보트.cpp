#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = people.size(),i=0,j=people.size()-1;
    sort(people.begin(),people.end());
    while(i<j){
        if(people[i]+people[j]<=limit){
            answer--;
            j--;
            i++;
        }else{
            j--;
        }
    }
    return answer;
}