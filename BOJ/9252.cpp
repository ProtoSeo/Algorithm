/*
문제
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 
모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

입력
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

출력
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를, 둘째 줄에 LCS를 출력한다.

LCS가 여러 가지인 경우에는 아무거나 출력하고, LCS의 길이가 0인 경우에는 둘째 줄을 출력하지 않는다.
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int d[1001][1001];
char sol[1001][1001];   //LCS를 출력하기 위해서 방향을 저장하기 위한 배열
int main(){
    string a,b;
    int i,j;
    cin >> a>>b;
    for(i=1;i<=a.length();i++){     //a문자열의 길이만큼 반복
        for(j=1;j<=b.length();j++){ //b문자열의 길이만큼 반복
            if(a[i-1]==b[j-1]){     //해당 좌표에서 문자가 같은경우
                d[i][j] = d[i-1][j-1]+1;    //이전 대각선의 방향에 저장되어 있는 수열의 길이보다, 길이가 1 늘어날수 있으므로 값이 증가할수있다.
                sol[i][j] = 'D';    //대각선으로 이동하는거 저장
            }else{
                d[i][j]= max(d[i-1][j],d[i][j-1]);  
                if(d[i][j] == d[i-1][j]){
                    sol[i][j] = 'U';    //위와 값이 같으면 위로 이동하도록 저장
                }else if(d[i][j] == d[i][j-1]){
                    sol[i][j] = 'L';    //왼쪽에서와 값이 같으면 왼쪽으로 이동하도록 저장
                }
            }
        }
    }
    //배열의 맨 끝에서부터 반복문을 수행하기 위해서 값을 초기화 해준다.
    i=a.length();   
    j=b.length();
    string ans;
    while(sol[i][j]!='\0'){ //맨 뒤에서부터 저장한 이동경로대로 이동하면서 LCS를 string에 저장한다.
        //해당 조건문은 이동 경로에 따라서 좌표값을 수정해준다.
        if(sol[i][j] =='D'){    
            i--,j--;
            ans += a[i];
        }else if(sol[i][j]=='U'){
            i--;
        }else if(sol[i][j]=='L'){
            j--;
        }
    }
    reverse(ans.begin(),ans.end()); //뒤에서부터 저장했으므로 역으로 저장되있으므로 이를 뒤집는다.
    cout << d[a.length()][b.length()]<<'\n';
    cout << ans;
}