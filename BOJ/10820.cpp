/*
문제
문자열 N개가 주어진다. 이때, 문자열에 포함되어 있는 소문자, 대문자, 숫자, 공백의 개수를 구하는 프로그램을 작성하시오.

각 문자열은 알파벳 소문자, 대문자, 숫자, 공백으로만 이루어져 있다.

입력
첫째 줄부터 N번째 줄까지 문자열이 주어진다. (1 ≤ N ≤ 100) 문자열의 길이는 100을 넘지 않는다.

출력
첫째 줄부터 N번째 줄까지 각각의 문자열에 대해서 소문자, 대문자, 숫자, 공백의 개수를 공백으로 구분해 출력한다.
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    
    while(getline(cin, str)&&str != ""){    //스페이스바 입력을 포함하므로, getline을 통해서 한줄 입력을 받는다. 
                                            //그리고 EOF나 아무것도 입력을 받을 때 까지 반복을 하도록 한다.
        int lower=0, upper=0, space=0, integer=0;
		for(int i=0;i<str.length();i++){    //입력받은 str의 길이만큼 반복문을 돌린다.
            //해당하는 소문자, 대문자, 숫자, 스페이스바 입력에 해당하는 char형일때 값을 1씩 증가시킨다.
            if(str[i]>=97&&str[i]<=122) lower++;    
            else if(str[i]>=65&&str[i]<=90) upper++;
            else if(str[i]>=48&&str[i]<=57) integer++;
            else if(str[i]==' ') space++;
        }
        cout << lower<<' '<< upper << ' ' << integer <<' ' <<space <<endl;  //출력
    }
}