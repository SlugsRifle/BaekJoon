def find_shark(board):
    iy = 0
    for y in board:
        ix = 0
        for x in y:
            if x ==9:
                return [ix,iy]
            ix += 1
        iy += 1
    return []

def bfs(board, point):
    visit = []
    q = [point.copy()]
    while q:
        s = len(q)
        for _ in range(s):
            n = q.pop(0)
            
        

n = int(input())
board = []
lvl, ate, time = 2, 0, 0
for _ in range(n):
    board.append(list(map(int,input().split())))
    
print("Shark Point:",find_shark(board))
 

