/*
문제
1부터 N까지의 수를 한 번씩 이용해서 최대 부분 증가 수열의 길이가 M이고, 최대 부분 감소 수열의 길이가 K인 수열을 출력한다.

입력
첫째 줄에 N M K가 주어진다. N은 500보다 작거나 같은 자연수, M과 K는 N보다 작거나 같은 자연수이다.

출력
첫째 줄에 문제의 정답을 출력한다. 정답이 없다면-1을 출력한다
*/
//참고 : https://www.slideshare.net/Baekjoon/baekjoon-online-judge-1201
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n,m,k,i,j;
    cin >> n >> m >> k;
    vector<int> seq;
    stack<int> res;
    if(m+k-1<=n&&n<=m*k){   //먼저 해당 n이 성립이 되는 조건을 확인해야한다.
        //n이 m+k-2보다 커야한다는 것은 당연하다.(-1까지 가능한 이유는 중간의 큰 값을 중복하면 가능하다.)
        //n이 m*k+1보다 작아야 하는 이유는 m*k+1이 되면 숫자가 하나가 부족하기 때문이다.
        int tmp = n;    //n과 m을 저장해준다.
        int size = m;
        /* 해당 반복문은 우리가 이 수열을 구할때 먼저 m개의 칸으로 나눈뒤 m개의 칸에서 뒤에서부터 k에 같거나 작은수를 넣어서 
        해당 수열을 구하게 하기 위해서 이다.(가장 뒷칸은 k개의 원소를 가진다고 해야하는데, 그 이유는 해당 칸에서 k를 만족하는
        최대 부분 감소수열을 구할것이기 때문이다.),(그리고 m개의 칸으로 나눈 이유는 해당 m개의 칸을 이용해서 최대 부분 증가수열을
        구하게 하기 위함이다.)
        */
        for(i=k;seq.size()!=size;){     //칸을 저장하는 vector의 크기가 size = m 과 같아진다면 종료
            //i를 이용해서 k와 같거나 작은수를 vector에 저장한다.
            if(n-i >= m-1){
                seq.push_back(i);
                n-=i;
                m--;
            }else{  //i만큼의 원소가 들어갈 자리가 없다면 i를 1 줄여본다.
                i--;
            }
        }
        for(i=0;i<size;i++){
            int temp = tmp-seq[i];  //temp변수를 이용해서 tmp에 있는 값을 꺼내서 해당 수열의 칸수만큼 뺀 뒤
            //아래의 반복문을 통해서 역으로 넣어준다.(부분 감소수열을 만드는 것이다.)
            for(j=1;j<=seq[i];j++){
                res.push(temp+j);
            }
            tmp = temp; //tmp에 temp로 값을 업데이트 해준다.
        }
        while(!res.empty()) cout << res.top()<<' ',res.pop();
    }else{
        cout<<-1;
    }    
}