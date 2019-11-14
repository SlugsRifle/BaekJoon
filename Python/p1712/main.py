i = input().split(" ");
a = int(i[0])
b = int(i[1])
c = int(i[2])
l = 0
m = 0
h = 0xffffffff

if (b >= c):
    print(-1)
else:
    while l<h:
        m = (h + l)//2
        if (a + b * m < c * m):
            h = m - 1
        else:
            l = m + 1
    print(h+1)
