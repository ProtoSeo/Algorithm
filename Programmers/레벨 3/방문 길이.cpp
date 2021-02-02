#include <string>
#include <set>
using namespace std;
int solution(string dirs) {
    pair<int,int> now = {0,0};
    set<pair<pair<int,int>,pair<int,int>>> s;
    for(char c: dirs){
        pair<int,int> prev = now;
        if(c=='U'){
            if(now.first<5) {
                now.first ++;
                s.insert({now,prev});
                s.insert({prev,now});
            }
        }else if(c=='D'){
            if(now.first>-5) {
                now.first --;
                s.insert({now,prev});
                s.insert({prev,now});
            }
        }else if(c=='R'){
            if(now.second<5){ 
                now.second ++;
                s.insert({now,prev});
                s.insert({prev,now});
            }
        }else if(c=='L'){
            if(now.second>-5){
                now.second --;  
                s.insert({now,prev});
                s.insert({prev,now});
            }
        }
    }

    return s.size()/2;
}