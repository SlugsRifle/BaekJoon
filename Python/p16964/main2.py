v = [False]*100001
nrr = []
n = int(input());
#print(n)
nr = [list(map(int,input().split())) for _ in range(1,n)]
#print(nr)
o = list(map(int,input().split()))
#print(o)
for _ in range(n+1):
    nrr.append(list())

for i in nr:
    nrr[i[0]].append(i[1])
#print(nrr)

c = 0
def dfs(x,nrr):
    global c
    if not nrr[x]:
        print(x,c,o[c])
        if x == o[c]:
            return True
        else:
            return False
    else:
        if x==o[c] and not v[x]:
            print(x,c,o[c])
            v[x] = True
            c+=1
            for _ in nrr[x]:
                for i in nrr[x]:
                    re = dfs(i,nrr)
                    if re:
                        return True
        else:
            return False
print(1 if dfs(1,nrr) else 0)