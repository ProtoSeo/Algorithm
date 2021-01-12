#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

const int NUMBERS = 10;
int toNumber(char ch) {return ch-'0';}
//트라이의 한 노드를 나타내는 객체
struct TrieNode{
    TrieNode* children[NUMBERS];
    bool terminal;  //  이 노드가 종료 노드인가?
    TrieNode(): terminal(false){
        memset(children,0,sizeof(children));
    }
    ~TrieNode(){
        for(int i=0;i<NUMBERS;++i){
            if(children[i]) delete children[i];
        }
    }

    // 이 노드를 루트로 하는 트라이에 문자열 key를 추가한다.
    void insert(const char* key){
        // 문자열이 끝나면 terminal만 참으로 바꾸고 종료
        if(*key==0){
            terminal = true;
        }else{
            int next = toNumber(*key);
            if(children[next] == NULL) children[next] = new TrieNode();

            children[next]->insert(key+1);
        }
    }

    //  이 노드를 루트로 하는 트라이에 문자열 key 와 대응되는 노드를 찾는다.
    // 없으면 NULL을 반환한다.
    bool find(const char* key){
        if(*key == 0) return true;
        if(terminal) return false;
        int next = toNumber(*key);
        if(children[next]==0) return 0;
        return children[next]->find(key+1);
    }

};
bool solution(vector<string> phone_book) {
    bool answer = true;
    TrieNode head;
    sort(phone_book.rbegin(),phone_book.rend());
    for(int i=0;i<phone_book.size();i++){
        string s= phone_book[i];
        if(i==0) {
            head.insert(s.c_str());
        }
        else{
            if(!head.find(s.c_str())){
                head.insert(s.c_str());
            }else{
                answer = false;
                break;
            }
        }
    }

    return answer;
}