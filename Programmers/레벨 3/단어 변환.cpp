#include <string>
#include <vector>
#define MIN(a,b) (((a)<(b))? (a):(b)) 
using namespace std;
vector<string> w_copy;
int a= 1e9;
int distance(string a,string b){
    int dist = 0;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]) dist++;
    }
    return dist;
}
void DFS(string begin, string target,vector<bool> visited,int cnt){
    if(begin == target){
        a = MIN(a,cnt);
    }
    for(int i=0;i<w_copy.size();i++){
        if(!visited[i]&&distance(begin,w_copy[i])==1){
            visited[i] = true;
            DFS(w_copy[i],target,visited,cnt+1);
            visited[i] = false;
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    vector<bool> visited(words.size(),0);
    w_copy = words;
    DFS(begin,target,visited,0);
    if(a==1e9) a=0;
    return a;
}