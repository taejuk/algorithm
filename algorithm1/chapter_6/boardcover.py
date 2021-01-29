direction = [[[0,0],[1,0],[0,1]],[[0,0],[0,1],[1,1]],[[0,0],[1,0],[1,1]],[[0,0],[1,0],[1,-1]]]
def possible(board, shape, cur):
    for i in shape:
        if(board[cur[0]+i[0]][cur[1]+i[1]]=='#'):
            return False
    return True
    

def set(board, shape, cur, dec):
    newBoard = board
    if dec == 1:
        for i in shape:
            newBoard[cur[0]+i[0]][cur[1]+i[1]] = '#'
    else:
        for i in shape:
            newBoard[cur[0]+i[0]][cur[1]+i[1]] = '.'
    return newBoard
def count(board,h,w):
    sum = 0
    ret = 0
    for i in range(0,h+2):
        for j in range(0,w+2):
            if board[i][j] == '.':
                sum +=1
    if sum == 0:
        return 1
    cur = []
    for i in range(0,h+2):
        if len(cur) != 0:
            break
        for j in range(0,w+2):
            if board[i][j] == '.':
                cur.append(i)
                cur.append(j)
                break
    for i in range(4):
        shape = direction[i]
        if possible(board,shape,cur)==True:
            board = set(board,shape,cur,1)
            ret += count(board,h,w)
            board = set(board,shape,cur,-1)
    return ret



if __name__=="__main__":
    h = int(input())
    w = int(input())
    board = []
    blocks = ['#']*(w+2)
    board.append(blocks)

    for i in range(0,h):
        line = input()
        temp = ['#']
        for i in range(0, len(line)):
            temp.append(line[i])
        temp.append('#')
        board.append(temp)
    board.append(blocks)
    res = count(board,h,w)
    print(res)
