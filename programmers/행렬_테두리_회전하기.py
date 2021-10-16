def printBoard(board):
    for row in board:
        print(row)

def rotate(board, query, answer):
    for i in range(len(query)):
        query[i] -= 1
    
    x, y = query[0], query[1]
    start = board[x][y]
    changed = []
    
    for i in range(query[2]-query[0]):
        board[x][y] = board[x+1][y]
        changed.append(board[x][y])
        x += 1
    for i in range(query[3]-query[1]):
        board[x][y] = board[x][y+1]
        changed.append(board[x][y])
        y += 1
    for i in range(query[2]-query[0]):
        board[x][y] = board[x-1][y]
        changed.append(board[x][y])
        x -= 1
    for i in range(query[3]-query[1]):
        board[x][y] = board[x][y-1]
        changed.append(board[x][y])
        y -= 1
    board[x][y+1] = start
    changed.append(start)
    answer.append(min(changed))
        
def solution(rows, columns, queries):
    answer = []
    board = []
    for i in range(rows):
        row = []
        for j in range(columns):
            row.append(i*columns+j+1)
        board.append(row)
    
    for q in queries:
        rotate(board, q, answer)
    
    return answer