import queue
import sys
sys.setrecursionlimit(100000000)
n,k=map(int,input().split(" "))
v=[]
tmp = -1
def dfs(a,b,c):
    if a in v:
        return -1;
    if c==50:
        return -1;
    if a==b:
        print(a,b,c)
        return c;
    v.append(a)
    if a!=0 and a<b:
        dfs(a*2,b,c+1)
    if a<b:
        dfs(a+1,b,c+1)
    if a!=0:
        dfs(a-1,b,c+1)

dfs(n,k,0)
