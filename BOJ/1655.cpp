/*
문제
수빈이는 동생에게 "가운데를 말해요" 게임을 가르쳐주고 있다. 수빈이가 정수를 하나씩 외칠때마다 동생은 지금까지 수빈이가 말한 수 중에서 중간값을 말해야 한다. 
만약, 그동안 수빈이가 외친 수의 개수가 짝수개라면 중간에 있는 두 수 중에서 작은 수를 말해야 한다.

예를 들어 수빈이가 동생에게 1, 5, 2, 10, -99, 7, 5를 순서대로 외쳤다고 하면, 동생은 1, 1, 2, 2, 2, 2, 5를 차례대로 말해야 한다. 
수빈이가 외치는 수가 주어졌을 때, 동생이 말해야 하는 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에는 수빈이가 외치는 정수의 개수 N이 주어진다. N은 1보다 크거나 같고, 100,000보다 작거나 같은 자연수이다. 
그 다음 N줄에 걸쳐서 수빈이가 외치는 정수가 차례대로 주어진다. 정수는 -10,000보다 크거나 같고, 10,000보다 작거나 같다.

출력
한 줄에 하나씩 N줄에 걸쳐 수빈이의 동생이 말해야하는 수를 순서대로 출력한다.
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    priority_queue<int,vector<int>,less_equal<int>> small;  // 큰게 위로 올라오도록
    priority_queue<int,vector<int>,greater<int>> big;   //작은값이 위로 올라오도록
    int n,i;
    cin >>n;
    
    vector<int> input(n);   //입력값을 저장하는 vector
    vector<int> res(n);     //출력값을 저장하는 vector
    
    for(i=0;i<n;i++){   //입력
        cin >> input[i];
    }
    res[0] = input[0];
    if(input[0]<input[1]){      
        small.push(input[0]);
        big.push(input[1]);
        res[1] = input[0];
    }else{      
        small.push(input[1]);
        big.push(input[0]);
        res[1] = input[1];
    }
    for(i=2;i<n;i++){   // 이 방법의 중점은 양쪽 우선순위 큐의 크기 차이가 1이 나지 않도록 하는것임.
        if(res[i-1]<input[i]){  //저번 중간값보다 값이 크다면
            if(big.size()>small.size()){    
                int temp = big.top();
                big.pop();
                small.push(temp);
                big.push(input[i]);
            }
            else{   //size가 같은경우나 오히려 작은경우
                big.push(input[i]);
            }
        }
        else{   //중간값보다 값이 작거나 같다면
            if(big.size()<small.size()){
                int temp = small.top();
                small.pop();
                big.push(temp);
                small.push(input[i]);
            }
            else{   
                small.push(input[i]);
            }
        }
        //res 를 구하는 조건문
        if((i-1) % 2==0){   //i-1이 짝수일 때
            if(big.top()>small.top()){  //양쪽 큐에 크기가 같을때는 값이 작은쪽이 중간값이다.
                res[i] = small.top();
            }else{
                res[i] = big.top();
            }
        }else{  //i-1이 홀수일 때는 size가 1 큰 우선순위 큐에서 값을 가져와야 중간값이다.
            if(big.size()>small.size()){
                res[i] = big.top();
            }else{
                res[i] = small.top();
            }
        }
    }
    for(i=0;i<n;i++){   //출력
        cout << res[i] <<' ';
    }
}