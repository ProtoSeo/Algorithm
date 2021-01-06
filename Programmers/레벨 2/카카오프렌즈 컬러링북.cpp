#include <vector>
#include <string.h>
#include <queue>
#include <map>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int arr[101][101], dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    memset(arr,0,sizeof(arr));
    queue<pair<int,int>> q;
    map<int,int> save;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(picture[i][j]>0&&arr[i][j]==0){
                number_of_area++;
                arr[i][j] = number_of_area;
                q.push({i,j});
                int color = picture[i][j];
                while(!q.empty()){
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int yy = y+dy[k];
                        int xx = x+dx[k];
                        if(yy<m&&yy>=0&&xx<n&&xx>=0&&arr[yy][xx]==0&&color==picture[yy][xx]){
                            q.push({yy,xx});
                            arr[yy][xx] = number_of_area;
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]>0) save[arr[i][j]]++;
        }
    }
    for(auto it = save.begin();it!= save.end();++it){
        if(max_size_of_one_area<it->second){
            max_size_of_one_area = it->second;
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}