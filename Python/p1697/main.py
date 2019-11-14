n,k=map(int,input().split(" "))
tn = k
tk = n
c =0
while tn!=tk:
    c+=1
    print(tn,c)
    if tn%2==0 and tn>tk:
        tn//=2
    elif tn>tk:
        tn+=1
    elif tn<tk:
        tn+=1
    else:
        tn-=1
print(c)
