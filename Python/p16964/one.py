import collections
n=int(input())
a=[[map(int,input().split())]*for _ in range(n-1)]
b=collections.deque([map(int,input())])
s=[]
v=[False]*100000
v[1]=True
def f(x,y):
    while True:
        t=b.popleft()
        if len(b)==0:
            return 0
        elif  len(s)==0:
            return 1
        if v[t]==False and s:
            s.append(t)
            v[s[-1]]=True
        else:
            s.pop()
           
            
print(f(a,b))