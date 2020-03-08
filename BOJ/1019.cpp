/*
문제
지민이는 N쪽인 책이 한권 있다. 첫 페이지는 1쪽이고, 마지막 페이지는 N쪽이다. 
각 숫자가 모두 몇 번이 나오는지 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. N은 1,000,000,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 0이 총 몇 번 나오는지, 1이 총 몇 번 나오는지, ..., 9가 총 몇 번 나오는지를 출력한다.
*/
//hint => https://www.slideshare.net/Baekjoon/baekjoon-online-judge-1019
#include<iostream>
using namespace std;

int digit = 1;
int count[10];
void calc(int n){   //숫자를 입력받은 다음 해당하는 숫자들을 count해주는 함수
    while(n>0){
        count[n%10]+=digit;
        n /=10;
    }
}

int main(){
    int input,start=1;
    cin >> input;
    while(start<=input){
        //입력받은 수의 마지막 자리를 9로 만드는 작업,동시에 calc함수를 이용해서 9로 만드는 동안의 숫자를 count한다.
        while(input%10 != 9 &&start<=input){
            calc(input);
            input--;
        }
        if(input<start) break;

        //시작페이지의 마지막 자리를 0으로 만드는 작업, 동시에 calc함수를 이용해서 끝자리를 0으로 만드는 동안의 숫자를 count한다.
        while(start%10 !=0 &&start <=input){
            calc(start);
            start++;
        }
        //이후 /10을 해서 0~9까지의 숫자를 셀 준비를 한다.
        start /=10;
        input /=10;
        
         for (int i = 0; i < 10; i++) {
            count[i] += (input - start + 1)*digit;  //이후 자릿수에 맞게 값을 곱해준다.
        }
        digit*=10;  // /10을 했으므로 자릿수에 10을 곱해준다.
    }
    for(int i=0;i<10;i++){
        cout << count[i]<<' ';
    }
}