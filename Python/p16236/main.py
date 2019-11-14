def find_feed(board,n,lvl):
    visited = []
    q = []
    
    for i in range(n):
        if 9 in board[i]:
            q.append([i,board[i].index(9),0])
            board[i][board[i].index(9)] = 0
    
    while q:
        c = q.pop(0)
        
        if 0 < board[c[0]][c[1]] and board[c[0]][c[1]] < lvl:
            board[c[0]][c[1]] = 9

            print()
            print("time:",c[2])
            print()
            
            for qwe in range(n):
                 print(board[qwe])
                
            return c[2]
        
        if c not in visited:
            visited.append(c)
            
            if 0 < c[0] and [c[0]-1,c[1]] not in visited and [c[0]-1,c[1]] not in q and board[c[0]-1][c[1]] <= lvl:
                q.append([c[0]-1,c[1],c[2]+1])
                
            if 0 < c[1] and [c[0],c[1]-1] not in visited and [c[0],c[1]-1] not in q and board[c[0]][c[1]-1] <= lvl:
                q.append([c[0],c[1]-1,c[2]+1])
                
            if c[0] < n-1 and [c[0]+1,c[1]] not in visited and [c[0]+1,c[1]] not in q and board[c[0]+1][c[1]] <= lvl:
                q.append([c[0]+1,c[1],c[2]+1])
                
            if c[1] < n-1 and [c[0],c[1]+1] not in visited and [c[0],c[1]+1] not in q and board[c[0]][c[1]+1] <= lvl:
                q.append([c[0],c[1]+1,c[2]+1])

n = int(input())
board = []
lvl, ate, time = 2, 0, 0
for _ in range(n):
    board.append(list(map(int,input().split())))

while list(filter(lambda x:0 < x < lvl,sum(board,[]))) != []:
    
    print()
    print("========================================")
    print(lvl,ate)
    
    time += find_feed(board,n,lvl)
    ate += 1
    
    if lvl == ate:
        lvl += 1
        ate = 0

print(time)