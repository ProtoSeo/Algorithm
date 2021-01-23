#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> map;

vector<vector<int>> rotation(vector<vector<int>> key){
    vector<vector<int>> rot;
    for(int i=0;i<key.size();i++){
        vector<int> tmp;
        for(int j=key[i].size()-1;j>=0;j--){
            tmp.push_back(key[j][i]);
        }
        rot.push_back(tmp);
    }
    return rot;
}

bool validation(vector<pair<int,int>> point,vector<vector<int>> key,int size){
    for(auto v:point){
        int i = v.first;
        int j = v.second;
        vector<vector<int>> tmp = map;
        for(int n = i;n<i+key.size();n++){
            for(int m = j;m<j+key.size();m++){
                tmp[n][m]+=key[n-i][m-j];
            }
        }
        bool chk = true;
        for(int n=0;n<size;n++){
            for(int m=0;m<size;m++){
                if(tmp[n+key.size()][m+key.size()]==0||tmp[n+key.size()][m+key.size()]==2){
                    chk = false;
                    break;
                }
            }
            if(!chk) break;
        }
        if(chk) return true;
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int lock_s = lock.size(),key_s = key.size();
    int b = (lock_s+((key_s-1)*2));
    
    for(int i=0;i<=b;i++){
        vector<int> tmp;
        for(int j=0;j<=b;j++){
            if(key_s<=i&&i<key_s+lock_s&&key_s<=j&&j<key_s+lock_s){
                tmp.push_back(lock[i-key_s][j-key_s]);    
            }else{
                tmp.push_back(0);
            }
        }
        map.push_back(tmp);
    }
    vector<pair<int,int>> point;
    for(int i=1;i<lock_s+key_s;i++){
        for(int j=1;j<lock_s+key_s;j++){
            point.push_back({i,j});
        }
    }

    for(int t=0;t<4;t++){
        if(validation(point,key,lock_s)) return true;
        key = rotation(key);
    }
    return false;
}