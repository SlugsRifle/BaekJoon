k,p=map(int,input().split())
j=[int(input()) for _ in range(k)]
c=sum(j)//p
print(list(filter(lambda x:sum(i//c for i in j)==x,range(c,1,-1))))


k,p=map(int,input().split())
j=[int(input()) for _ in range(0,k)]
c=sum(j)//p
print(list(filter(lambda x:sum(i//x for i in j)==p,range(c,0,-1)))[0])