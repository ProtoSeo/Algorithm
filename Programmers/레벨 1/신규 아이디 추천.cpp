#include <string>
#include <vector>
using namespace std;

string solution(string new_id) {
    string tmp="";
    for(int i=0;i<new_id.size();i++){
        if('A'<=new_id[i]&&new_id[i]<='Z'){
            new_id[i] =new_id[i] + ('a'-'A');
        }
    }
    for(int i=0;i<new_id.size();i++){
        if(('a'<=new_id[i]&&new_id[i]<='z')||('0'<=new_id[i]&&new_id[i]<='9')){               tmp+=new_id[i];
        }else if(new_id[i]=='_'||new_id[i]=='.'||new_id[i]=='-'){
            tmp+=new_id[i];
        }
    }
    new_id = tmp;
    tmp="";
    for(int i=0;i<new_id.size();){
        if(new_id[i]=='.'){
            int j =i+1;
            for(;j<new_id.size();j++){
                if(new_id[j]=='.') continue;
                else break;
            }
            tmp += '.';
            i=j;
        }else{
            tmp += new_id[i];
            i++;
        }
    }
    new_id = tmp;
    tmp = "";
    if(new_id[0]=='.'){
        new_id = new_id.substr(1);
    }
    if(new_id[new_id.size()-1]=='.'){
        new_id = new_id.substr(0,new_id.size()-1);
    }
    if(new_id.size()==0){
        new_id += 'a';
    }else if(new_id.size()>=16){
        new_id = new_id.substr(0,15);
        if(new_id[new_id.size()-1]=='.'){
            new_id = new_id.substr(0,new_id.size()-1);
        }
    }
    if(new_id.size()<=2){
        while(new_id.size()!=3){
            new_id += new_id[new_id.size()-1];
        }
    }
    return new_id;
}