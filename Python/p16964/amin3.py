import sys
sys.setrecursionlimit(10)

v = [0]*100001
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
    global c,v
    
    if not nrr[x]:
        if c < n:
            if x == o[c] and not v[x]:
                v[x] = 1
                c+=1
                return 1
            else:
                return 0
        else:
            return 0
    else:
        if c < n:
            if x == o[c] and not v[x]:
                v[x] = 1
                r = 0
                c+=1
                for _ in nrr[x]:
                    for i in nrr[x]:
                        re = dfs(i,nrr)
                        if re:
                            r+=1
                if r == len(nrr[x]):
                    return 1
                else:
                    return 0
            else:
                return 0
        else:
            return 0
        
        return 0
                
    
print(dfs(1,nrr))