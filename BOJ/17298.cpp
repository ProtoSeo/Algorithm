/*
문제
크기가 N인 수열 A = A1, A2, ..., AN이 있다. 수열의 각 원소 Ai에 대해서 오큰수 NGE(i)를 구하려고 한다.
Ai의 오큰수는 오른쪽에 있으면서 Ai보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다. 그러한 수가 없는 경우에 오큰수는 -1이다.

예를 들어, A = [3, 5, 2, 7]인 경우 NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1이다. 
A = [9, 5, 4, 8]인 경우에는 NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째에 수열 A의 원소 A1, A2, ..., AN (1 ≤ Ai ≤ 1,000,000)이 주어진다.

출력
총 N개의 수 NGE(1), NGE(2), ..., NGE(N)을 공백으로 구분해 출력한다.
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t, i;
    cin >> t;

    stack <int> stk;
    vector <int> vec(t);
    vector <int> ans(t, -1);    //-1로 초기화를 해서 오큰수를 구하지 않는 자리에 -1이 나올수있게 한다.

    for (i = 0; i < t; i++) cin >> vec[i];

    for (i = 0; i < t; i++) {
        // 오큰수를 구하지 않은 index를 stk에 저장한다. 
        // 그리고 반복문을 통해서 해당 index와 vec에 입력된 값을 비교를 통해서 이를 ans 벡터에 저장한다.
        while(!stk.empty() && vec[stk.top()] < vec[i]) {
            ans[stk.top()] = vec[i];
            stk.pop();
        }
        stk.push(i);
    }
    for (i = 0; i < ans.size(); i++) cout << ans[i]<<' ';
}