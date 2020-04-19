/*
백준 11497번 : 통나무 건너뛰기
https://www.acmicpc.net/problem/11497
*/
#include <iostream>
#include <algorithm>
#include <vector>
#define ABS(a) ((a<0) ? -(a):(a))
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	while (t-- > 0) {
		int i, k;
		cin >> k;
		vector<int> a(k);	//처음 입력을 저장하기 위한 배열
		vector<int> b(k);	//그 다음 greedy하게 값을 뿌린다음 저장할 배열
		for (i = 0; i < k; i++) cin >> a[i];	//입력
		sort(a.begin(), a.end());	//정렬
		for (i = 0; i < k; i++) {	//정렬을 한 다음 큰수를 가운데에 넣고, 그 다음 큰수는 왼쪽 그다음은 오른쪽, 이런식으로 흩뿌려서 값을 저장한다.
			if (i % 2 == 0) b[i / 2] = a[i];
			else b[k - (i / 2 + 1)] = a[i];
		}
		//초기의 max값은 현재 이 배열이 원통형이라고 생각을 해야하므로, 뒤와 처음 부분의 값을 max라고 가정한다.
		int max = ABS(b[k-1]-b[0]);	
		for (i = 0; i < k - 1; i++) {	
			int tmp = ABS(b[i + 1] - b[i]);		//오른쪽의 값만 확인을 해서 절대값을 저장한다.
			if (tmp > max) max = tmp;	//max값과 비교를 한다음 큰 값을 저장한다.
		}
		cout <<max << '\n';
	}
}