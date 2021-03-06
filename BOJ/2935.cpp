/*
문제
수업 시간에 떠드는 두 학생이 있다. 두 학생은 수업에 집중하는 대신에 글로벌 경제 위기에 대해서 토론하고 있었다. 
토론이 점점 과열되면서 두 학생은 목소리를 높였고, 결국 선생님은 크게 분노하였다.
이렇게 학생들이 수업 시간에 떠드는 문제는 어떻게 해결해야 할까?
얼마전에 초등학교 선생님으로 취직한 상근이는 이 문제를 수학 문제로 해결한다. 
학생들을 진정시키기 위해 칠판에 수학 문제를 써주고, 아이들에게 조용히 이 문제를 풀게 한다. 
학생들이 문제를 금방 풀고 다시 떠드는 것을 방지하기 위해서, 숫자를 매우 크게 한다.

아직 초등학교이기 때문에, 학생들은 덧셈과 곱셈만 배웠다. 
또, 아직 10의 제곱꼴을 제외한 다른 수는 학교에서 배우지 않았기 때문에, 선생님이 써주는 수는 모두 10의 제곱 형태이다.
쉬는 시간까지 문제를 푸는 것을 막기 위해서, 선생님이 써주는 숫자는 최대 100자리이다.
칠판에 쓰여 있는 문제가 주어졌을 때, 결과를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 양의 정수 A가 주어진다.
둘째 줄에 연산자 + 또는 *가 주어진다.
셋째 줄에 양의 정수 B가 주어진다.
A와 B는 모두 10의 제곱 형태이고, 길이는 최대 100자리이다.

출력
첫째 줄에 결과를 출력한다. 결과는 A+B 또는 A*B이며, 입력에서 주어지는 연산자에 의해 결정된다. 
*/
#include<iostream>
using namespace std;

int main(){
    string a,b,c,str="1";
    cin>>a>>b>>c;   
    int length =0,aLen = a.length(),cLen = c.length();  //10의 거듭제곱을 입력받아서 길이를 저장한다.
    
    if(b=="+"){ //+연산 일때의 조건문
        //+일때는 경우를 3가지르 나누는데 처음 입력받은 수가 길이가 길경우, 같은경우, 짧은경우로 나누어서 문제를 해결한다.
        if(aLen > cLen) cout<<a.replace(aLen-cLen,cLen,c);  
        else if(aLen==cLen) cout<< a.replace(0,1,"2");
        else if(aLen<cLen) cout<<c.replace(cLen-aLen,aLen,a);
    }else{     //*연산 일때의 조건문
        length = a.length()+c.length()-2;   //곱하면 10의 제곱들끼리 더해지므로 해당 길이를 더하고 길이만큼 0을 출력한다.
        while(length--) str+="0";
        cout<<str;
    }
}