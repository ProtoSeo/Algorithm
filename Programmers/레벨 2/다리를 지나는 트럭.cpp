#include <string>
#include <vector>
#include<queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0,totalWeight= 0,carCnt=0,num=0,finCarCnt=0;
    queue<int> bridge;
    while(finCarCnt!=truck_weights.size()){
        answer++;
        int nowTruck = 0,finCar=0;
        if(!bridge.empty()&&bridge.size()==bridge_length) finCar = bridge.front(); 
        if(totalWeight+truck_weights[num]-finCar<=weight){
            nowTruck = truck_weights[num++];
            totalWeight += nowTruck;
        }
        if(bridge.size()<bridge_length){
            bridge.push(nowTruck);
        }else if(bridge.size()==bridge_length){
            if(finCar!=0){
                totalWeight -= finCar;
                finCarCnt++;
            }
            bridge.pop();
            bridge.push(nowTruck);
        }
    }
    return answer;
}