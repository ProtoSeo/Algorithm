#include <string>
#include <vector>

using namespace std;
string week[] = {"FRI","SAT","SUN","MON","TUE","WED","THU"};
string solution(int a, int b) {
    string answer = "";
    int day = 0;
    //month배열을 만들어서 해결할 수도 있음(해당하는 index마다 해당 월의 날짜를 저장하도록)
    for(int i=1;i<a;i++){
        if(i==1||i==3||i==5||i== 7||i== 8||i==10){
            day += 31;
        }else if(i==4||i==6||i==9||i==11){
            day += 30;
        }else if(i==2){
            day+=29;
        }
    }
    day+=b;
    answer = week[(day-1)%7];
    return answer;
}