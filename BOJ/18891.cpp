/*
백준 18891번 : 제21대 국회의원 선거
https://www.acmicpc.net/problem/18891
*/
#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
struct party{   //정당 구조체
    string name;
    int s=0,r=0,t=0;
    double p=0,vote=0,vote_rate=0,temp=0;
};
vector<party> v1;    //의석 할당 정당
vector<party> v2;    //의석 할당 정당 X
queue<party> tmpq;
//double값과 int값을 저장하는 pair를 문제의 조건에 맞게 정렬하기 위한 함수
bool cmp1(const pair<double,int>& a,const pair<double,int>& b){
    if(a.first == b.first){
        return a.second<b.second;
    }
    return a.first>b.first;
}
//int값과 string값을 저장하는 pair를 문제의 조건에 맞게 정렬하기 위한 함수
bool cmp2(const pair<int,string>& a,const pair<int,string>& b){
    if(a.first == b.first){
        return a.second<b.second;
    }
    return a.first>b.first;
}
int P,V;
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int i,all_r=0,available_vote=0;
    int seat_party_vote=0;  //의석할당정당의 득표수를 모든 의석할당정당의 득표수의 합계로 나누어 다시 산출하기 위해서 사용
    int sigma_s = 0;    // 각 정당별 연동배분의석수의 합계
    int R = 0;     //의석할당정당이 아닌 정당의 지역구 당선인 수 총합 + 무소속 지역구 당선인 수
    cin >> P>>V;
    for(i=0;i<P;i++){
        string name;
        party tmp;
        int r,vote;     //r 은 지역구 의석수, vote는 득표수
        cin >> name >> r >> vote;
        available_vote += vote;
        all_r +=r;
        tmp.name = name;
        tmp.r= r;
        tmp.vote_rate = vote;   //나중에 투표율을 계산하기 위해서 득표수를 저장해 놓는다.
        tmpq.push(tmp);
    }
    R += 253 - all_r;   //현재는 무소속 의원의 수만 들어가 있다.
    while(!tmpq.empty()){  //의석 할당 정당인지 아닌지 판단을 한다.
        party tmp = tmpq.front(),par;
        tmpq.pop();
        string name = tmp.name;
        int r = tmp.r;
        double vote_number = tmp.vote_rate;    //현재는 득표수가 저장되어 있다.
        double vote_rate = vote_number/available_vote;    //득표율은 현재 저장된 득표수/유효 투표수 이다.(무효표 제외) 
        par.name = name;
        par.r = r;
        par.vote = vote_number;
        par.vote_rate = vote_rate;

        if(r>=5||vote_rate>=0.03){  //의석 할당 정당의 경우
            v1.push_back(par);
            seat_party_vote += vote_number;
        }else{
            v2.push_back(par);
            R += (int)par.r;    //의석할당정당이 아닌 정당의 지역구 당선인 수를 더한다.
        }
    }
    //p와 s를 이제 계산할 반복문 이다.
    for(i=0;i<v1.size();i++){
        v1[i].p = v1[i].vote / seat_party_vote;
        double s = ((300-R)*v1[i].p - v1[i].r)/2;
        if(s<=0){
            v1[i].s =0;
        }else{
            v1[i].s = round(s);
            sigma_s += v1[i].s;
        }
    }

    //단계 2-1 각 정당별 연동배분의석수의 합계 < 30석일 경우 -> 잔여의석에 대해 기존 의석배분방식(병립형) 적용 배분
    if(sigma_s<30){
        vector<pair<double,int>> vec_seat;
        int seat_cnt=0;     //30석이 넘는지 확인
        for(i=0;i<v1.size();i++){
            double s = v1[i].s + (30-sigma_s)*(v1[i].p);
            if(s<=0){
                v1[i].s =0;
            }else{
                v1[i].s = (int)s;
                vec_seat.push_back({s-(int)s,i});
                seat_cnt +=v1[i].s;
            }
        }
        //계산된 값의 정수 부분을 먼저 배분하고, 나머지는 총 연동배분의석수가 30석이 될 때까지 소수점 이하의 수가 큰 순서대로 배분한다.
        if(seat_cnt<30){
            sort(vec_seat.begin(),vec_seat.end(),cmp1);
            for(auto it = vec_seat.begin();it!=vec_seat.end();++it){
                v1[it->second].s++;
                seat_cnt++;
                if(seat_cnt==30) break;
            }
        }
    }else if(sigma_s>30){   //단계 2-2 각 정당별 연동배분의석수의 합계 > 30석 -> 각 정당별 연동배분의석수비율대로 배분
        vector<pair<double,int>> vec_seat;
        int seat_cnt=0;     //30석이 넘는지 확인
        for(i=0;i<v1.size();i++){
            double s = (30 * v1[i].s) /(double)sigma_s;
            if(s<=0){
                v1[i].s =0;
            }else{
                v1[i].s = (int)s;
                vec_seat.push_back({s-(int)s,i});
                seat_cnt +=v1[i].s;
            }
        }
        //계산된 값의 정수 부분을 먼저 배분하고, 나머지는 총 연동배분의석수가 30석이 될 때까지 소수점 이하의 수가 큰 순서대로 배분한다.
        if(seat_cnt<30){
            sort(vec_seat.begin(),vec_seat.end(),cmp1);
            for(auto it = vec_seat.begin();it!=vec_seat.end();++it){
                v1[it->second].s++;
                seat_cnt++;
                if(seat_cnt==30) break;
            }
        }
    }
    //단계 3 17석에 대해 기존 의석배분방식(병립형) 적용 배분
    {
        vector<pair<double,int>> vec_seat;
        int seat_cnt=0;     //17석이 넘는지 확인
        for(i=0;i<v1.size();i++){
            double t = (17 * v1[i].p); 
            v1[i].t = (int)t;
            vec_seat.push_back({t-(int)t,i});
            seat_cnt +=v1[i].t;
        }
        //계산된 값의 정수 부분을 먼저 배분하고, 17석이 될 때까지 소수점 이하의 수가 큰 순서대로 배분한다.
        if(seat_cnt<17){
            sort(vec_seat.begin(),vec_seat.end(),cmp1);
            for(auto it = vec_seat.begin();it!=vec_seat.end();++it){
                v1[it->second].t++;
                seat_cnt++;
                if(seat_cnt==17) break;
            }
        }
    }

    //v1과 v2에서 받아와서 마지막 정렬(의석할당정당 o + 의석할당정당 x)
    vector<pair<int,string>> ans;
    for(i=0;i<v1.size();i++){
        ans.push_back({v1[i].r+v1[i].t+v1[i].s,v1[i].name});
    }
    for(i=0;i<v2.size();i++){
        ans.push_back({v2[i].r+v2[i].t+v2[i].s,v2[i].name});
    }
    sort(ans.begin(),ans.end(),cmp2);
    for(auto it = ans.begin();it!=ans.end();it++){
        cout << it->second << ' ' << it->first<<'\n';
    }
}