import queue
n,k=map(int,input().split(" "))
v = []
q = queue.Queue()
q.put(n)
q.put(0)
while q.qsize():
    qd = q.get();
    d = q.get()+1
    if qd == k:
        print(d-1);
        break
    if not qd in v:
        q.put(qd*2);
        q.put(d);
        q.put(qd+1);
        q.put(d);
        q.put(qd-1);
        q.put(d);

