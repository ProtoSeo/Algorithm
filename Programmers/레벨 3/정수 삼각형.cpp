#include <string>
#include <vector>
#include <algorithm>
#define MAX(a,b) (((a)>(b))?(a):(b))
using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    for(int i=1;i<triangle.size();i++){
        for(int j=0;j<triangle[i].size();j++){
            int max = triangle[i][j];
            if(j==0){
                max += triangle[i-1][j];    
            }else if(j==triangle[i-1].size()){
                max += triangle[i-1][triangle[i-1].size()-1];
            }else{
                max += MAX(triangle[i-1][j],triangle[i-1][j-1]);
            }
            triangle[i][j] = max;
        }
    }
    return *max_element(triangle[triangle.size()-1].begin(),triangle[triangle.size()-1].end());
}