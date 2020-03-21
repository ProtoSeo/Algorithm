/*
문제
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 30, 50} 이고, 길이는 4이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
*/
#include<iostream>
using namespace std;
int a[1001],d[1001];

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n,i,j,max;
	cin >> n;   
	for (i = 1; i <= n; i++) cin >> a[i];
	max = d[1] = 1; //먼저 첫번째 수에서는 수열의 길이가 1이다.
    //O(n^2)방식으로 LIS를 구하는 방법
	for (i = 2; i <= n; i++) {
		d[i] = 1;   //해당 번째의 수에서 수열의 길이는 1이다.
		for (j = 1; j <= i; j++)    //첫번째부터 i까지에서 LIS를 찾는 반복문
			if (a[i] > a[j] && d[i] < d[j]+1)   //현재 a[i](현재 값)이 이전의 a[j](이전 값)보다 크고, 
                                                //현재 d[i](현재의 수열의 길이)가 이전 j까지의 수열의 길이(d[j])에 길이를 1을 더한것보다 작다면 
                d[i] = d[j] + 1;    //현재 수열의 길이를 업데이트 해준다.(즉 해당 인덱스를 선택했을때 수열의 길이가 길어지는가?)
		if (max < d[i]) max = d[i]; //최대길이를 구학기 위한 조건문
	}
	cout << max;
}