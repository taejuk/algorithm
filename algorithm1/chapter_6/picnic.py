def countCouples(cur, couples): #n = 총 학생 수, cur= 현재 학생 번호
    n = len(cur)
    idx = -1
    for i in range(0,len(cur)):
        if cur[i] == False:
            idx = i
            break
    if idx == -1:
        return 1
    
    ret = 0
    for i in range(idx+1, n):
        if couples[idx][i] == 1 and cur[i] == False:
            cur[idx] = True
            cur[i] = True
            ret += countCouples(cur, couples)
            cur[idx] = False
            cur[i] = False
    return ret


if __name__=="__main__":
    n = int(input())
    m = int(input())
    data = list(map(int,input().split()))
    couples = [[0]*n for i in range(n)]
    cur = [False]*n
    for i in range(0,len(data),2):
        a = data[i]
        b = data[i+1]
        couples[a][b] = 1
        couples[b][a] = 1
    print(countCouples(cur, couples))
    
    
