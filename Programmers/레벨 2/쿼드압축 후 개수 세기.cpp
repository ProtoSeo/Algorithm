#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int>> arr_copy; 
int dx[3] ={1,0,1}, dy[3] = {0,1,1};
vector<int> quad(int x1,int x2,int y1,int y2,int d){
    if(d==0){
        bool chk = true;
        for(int i=0;i<3;i++){
            if(arr_copy[y1][x1]!=arr_copy[y1+dy[i]][x1+dx[i]]){
                chk = false;
                break;
            }
        }
        if(chk){
            return {arr_copy[y1][x1]};
        }else{
            vector<int> v1 = {arr_copy[y1][x1]};
            v1.push_back(arr_copy[y1][x1+1]);
            v1.push_back(arr_copy[y1+1][x1]);
            v1.push_back(arr_copy[y1+1][x1+1]);
            return v1;
        }
    }
    vector<int> v1 = quad(x1,x1 + d,y1,y1+d,d/2);
    vector<int> v2 = quad(x1+d+1,x2,y1,y1+d,d/2);
    vector<int> v3 = quad(x1,x1+d,y1+d+1,y2,d/2);
    vector<int> v4 = quad(x1+d+1,x2,y1+d+1,y2,d/2);
    
    if(v1==v2&&v1==v3&&v1==v4&&v1.size()==1){
        return v1;
    }else{
        v1.insert(v1.end(),v2.begin(),v2.end());
        v1.insert(v1.end(),v3.begin(),v3.end());
        v1.insert(v1.end(),v4.begin(),v4.end());
        return v1;
    }
}
vector<int> solution(vector<vector<int>> arr) {
    arr_copy = arr;
    int zero=0,one=0;
    if(arr[0].size()==1){
        if(arr[0][0]==0) return {1,0};
        else return {0,1};
    }
    vector<int> tmp = quad(0,arr.size()-1,0,arr.size()-1,(arr.size()/2)-1);
    for(int i=0;i<tmp.size();i++){
        if(tmp[i]==0) zero++;
        else one ++;
    }
    return {zero,one};
}