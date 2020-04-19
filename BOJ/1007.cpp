/*
백준 1007번 : 벡터 매칭
https://www.acmicpc.net/problem/1007
*/
#include<iostream>
#include<cmath>
#include<limits>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
int n,x[21],y[21];
double res;
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    //소수점을 표시하기 위한 cout 설정
    cout <<fixed;
    cout.precision(8);
    int t;
    cin >>t;
    //요약: 벡터들을 입력받아서 조합을 이용해서 절반의 번호를 뽑아낸뒤 절반의 벡터를 각각 두개의 벡터로 합친뒤 두개의 벡터의 크기를 구해서 최소값을 찾는다.
    while(t--){
        cin >> n;
        int i,k = n/2;  //k는 n의 절반
        res = numeric_limits<double>::max();    //limits에서 받아온 double형의 최댓값
        vector<int> ind;
        for(i=0;i<n;i++){
            cin >> x[i]>> y[i];
            //k개 이전의 절반까지는 0을 k개 이후의 전반은 1을 넣어준다.
            if(i<k)
                ind.push_back(0);
            else
                ind.push_back(1);
        }
        //next_permutation을 이용해서 조합의 값을 구한다.
	    do{ 
            double xs=0,ys=0;
            for(int i=0;i<n;i++){
                //next_permutation에 의해서 ind vector에 저장된 0과 1의 위치가 바뀐다.(combination처럼)
                //ind가 1인 경우의 벡터, 0인 경우의 벡터를 각각 나누어서 벡터를 합쳐준다.
                if(!ind[i]){    
                    xs -= x[i];
                    ys -= y[i];
                }else {
                    xs += x[i];
                    ys += y[i];
                }
            }
            res =  min(res,sqrt(xs*xs + ys*ys));    //합친 뒤의 벡터의 크기를 구해서 최소값과 비교를 해준다.
	    }while(next_permutation(ind.begin(), ind.end()));
        cout << res<<'\n';
    }
}