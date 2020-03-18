/*
BOJ 1786 찾기
https://www.acmicpc.net/problem/1786
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> res; 
void KMP(string txt, string pat){   //KMP알고리즘
    int pt=1;   // text의 포인터 - 처음에 실패함수부터 구할것이므로 pt의 값을 1로 지정한다.
    int pp=0;   // pattern의 포인터 - pp는 0으로 둔다. (실패함수를 구할 때 어긋나게 시작을 하기위해서)
    vector<int> skip(pat.length()+1);   //실패값을 저장하는 vector
    skip[pt]=0;
    while(pt!=pat.length()){    //실패함수(입력받은 pattern문자열을 둘끼리서 KMP알고리즘을 사용하는 것과 같다.)
        // pt를 통해서 한칸씩 미뤄가면서 비교를 하는것과 같다.(그래서 ++pt를 하는 것)
        if(pat[pt] == pat[pp]){    //pattern에서 pt와 pp가 가리키는 문자가 같다면
            skip[++pt] = ++pp;  //해당 skip의 ++pt에는 ++pp를 저장한다.(pp의 값도 증가해서 다음 문자를 비교할 수 있도록 한다.)
        }else if(pp==0){    //pattern에서 pt와 pp가 가리키는 두 문자가 다르고 pp가 0이라면 (처음부터 문자열이 다르다면)
            skip[++pt] = pp;    //해당 skip의 ++pt에는 0을 저장한다.(skip값이 없다.)    
        }else{      //pattern에서 pt와 pp가 가리키는 두 문자가 다르고 pp가 0이 아니라면
            pp = skip[pp];  //skip에서 값을 꺼내서 pp에 저장한다.
        }
    }
    pt = pp =0; 
    while(pt != txt.length() && pp!=pat.length()){  //pt와 pp 두 포인터가 각자의 문자열의 범위를 벗어나지 않게 반복문을 돌린다.
        if(txt[pt]==pat[pp]){   //text와 pattern의 현재 각자 가리키는 문자가 같다면 다음 문자를 가리키도록 넘어간다.
            pt++;
            pp++;
        }else if(pp==0){    //만약 두 문자가 다르고 pp가 0이라면 (pattern의 처음부터 검사하는 경우이다.)
            pt++;   // pt를 증가시킨다.(text의 다음 문자를 받아야하므로)
        }else{  //?두 문자가 다르고 pp가 0이 아니라면 pp는 skip에서 값을 얻어와야 한다.(중복되는게 있는 경우)
            pp=skip[pp];    
        }
        if(pp ==pat.length()){  //pp가 pattern의 길이와 같다면 text에 pattern과 같은 문자열이 존재하는 것이다.
            res.push_back(pt-pp+1); //res vector에 해당 text에서의 문자열의 시작 위치를 저장한다.
            pp=skip[pp];    //그리고 다시 또 다른 문자열이 있는지 검사해야하므로 pp는 skip에서 다시 얻어온다.
        }
    }
}
int main(){
    string txt,pat;
    getline(cin,txt);
    getline(cin,pat);
    KMP(txt,pat);   //KMP알고리즘
    cout<< res.size() <<'\n';
    for(int i:res){
        cout <<i <<' ';
    }
}