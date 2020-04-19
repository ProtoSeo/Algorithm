"""
백준 2407번 : 조합
https://www.acmicpc.net/problem/2407
"""
import sys
input = sys.stdin.readline

a, b = input().split()
a = int(a)
b = int(b)
li = [[0]*101 for i in range(101)]
li[1][0] = 1
li[1][1] = 1
for i in range(2, 101):
    for j in range(101):
        if j == 0:
            li[i][j] = 1
        elif i == j:
            li[i][j] = 1
            break
        else:
            li[i][j] = li[i-1][j] + li[i-1][j-1]
print(li[a][b])