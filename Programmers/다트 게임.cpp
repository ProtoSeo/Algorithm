#include <string>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int cnt = 0;
    int arr[] = {0,0,0};
    for(int i=0;i<dartResult.size();){
        //해당 점수관련 처리
        int score = 0;
        if(dartResult[i]=='1'&&dartResult[i+1]=='0'){
            score = 10;
            i+=2;
        }else{
            score = (int)(dartResult[i]-'0');
            i+=1;
        }
        //점수 계산
        if(dartResult[i]=='D'){
            score *= score;
        }else if(dartResult[i]=='T'){
            score *= (score * score);
        }
        i++;
        // 옵션
        if(i<dartResult.size()&&(dartResult[i]<'0'||dartResult[i]>'9')){
            if(dartResult[i]=='*'){
                if(cnt==0){
                    score *= 2;
                }else{
                    score *= 2;
                    arr[cnt-1] *= 2;
                }
            }else if(dartResult[i]=='#'){
                score = -score;
            }
            i++;
        }
        arr[cnt] = score;
        cnt++;
    }
    for(int i=0;i<3;i++){
        answer += arr[i];
    }
    return answer;
}