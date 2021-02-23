def findOcr(idx, cur): #idx: 이때까지 구한 단어 수, cur: 마지막 단어의 인덱스
    if idx > 3:
        return 1    
    if cache[idx][cur] != 1:
        return cache[idx][cur]
    cache[idx][cur] = 0
    
    for i in range(5): #다음 단어의 인덱스가 i일 때,
        cache[idx][cur] = float(max(M[cur][r[idx]]*T[cur][i]*findOcr(idx+1, i),cache[idx][cur]))
    return cache[idx][cur]



if __name__ == "__main__":
    
    B = [1.0,0.0,0.0,0.0,0.0]
    #i번의 단어가 j번 단어일 확률
    T = [[0.1,0.6,0.1,0.1,0.1],[0.1, 0.1, 0.6, 0.1, 0.1],[0.1, 0.1, 0.1, 0.6, 0.1],[0.2,0.2,0.2,0.2,0.2],[0.2,0.2,0.2,0.2,0.2]]
    #i번 단어가 j번 단어로 분류할 확률
    M = [[0.8,0.1,0.0,0.1,0.0],[0.1,0.7,0.0,0.2,0.0],[0.0, 0.1, 0.8, 0.0, 0.1],[0.0, 0.0, 0.0, 0.5, 0.5],[0.0, 0.0, 0.0, 0.5, 0.5]]
    cache = [[1]*5 for i in range(5)]
    r = [0,1,1,3]
    ret = findOcr(0,0)
    print(ret)
    for i in range(len(cache)):
        print(cache[i])
    print("")