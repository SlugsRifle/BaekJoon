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
    
c = n-1
b = 0
def dfs(x):
    global nrr
    global c
    global b
    #print(x,nrr[x])
    #print(nrr[x])
    if o[0]!=1:
        return False
    
    if not nrr[x]: 
        #print(x,o[c],c,o[c]==x)
        if o[n-1]==x:
            c = n-2
            return True
        else:
            if x==o[c]:
                c-=1
                return True
            else:
                return False
    else:
        for _ in nrr[x]:
            for i in nrr[x]:
                #print(i)
                re = dfs(i)
                #print(x,o[c],c,re,o[c]==x)
                if re and o[c]==x:
                    c-=1
                    return True
    return False
print(dfs(1))