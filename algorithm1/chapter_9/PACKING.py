def packing(limit, idx):
    if idx > 5:
        return 0
    if limit == 0:
        cache[idx][limit] = 0
        return 0
    if limit<weight[idx]:
        cache[idx][limit] = packing(limit, idx+1)
        return cache[idx][limit]
    if cache[idx][limit] != -1:
        return cache[idx][limit]
    cache[idx][limit] = 0
    temp1 = wanted[idx]+packing(limit-weight[idx], idx+1)
    temp2 = packing(limit, idx+1)
    if temp1 < temp2:
        cache[idx][limit] = temp2
    elif temp1> temp2:
        cache[idx][limit] = temp1
    return cache[idx][limit]
    
def reconstruct(limit, idx):
    if idx == 6:
        return;
    if packing(limit, idx) == packing(limit, idx+1):
        reconstruct(limit, idx+1)
    else:
        choiced.append(idx)
        reconstruct(limit-weight[idx],idx+1)

if __name__=="__main__":
    weight = [6,2,4,4,2,10]
    wanted = [6,10,7,7,5,4]
    limited = 10
    cache = [[-1]*11 for j in range(6)] #현재 인덱스로부터 얻을 수 있는 최대 합.
    ret = packing(10,0)
    idx = 0
    choiced = []
    reconstruct(10,0)
    print(choiced)
    