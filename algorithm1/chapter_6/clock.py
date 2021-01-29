switch = [[0,1,2],[3,7,9,11],[4,10,14,15],[0,4,5,6,7],[6,7,8,10,12],[0,2,14,15],[3,14,15],[4,5,7,14,15],[1,2,3,4,5],[3,4,5,9,13]]

def changeClock(index, cur, times):
    for j in range(0,times):
        for i in switch[index]:
            cur[i] = cur[i] + 3
            cur[i] = cur[i] % 12
    return cur

def backClock(index, cur, times):
    for j in range(0,times):
        for i in switch[index]:
            cur[i] = cur[i] - 3
            cur[i] = cur[i] % 12
    return cur

def setOClock(times, index, cur):
    correct = 0
    ret = 100
    for i in cur:
        if i % 12 == 0:
            correct += 1
    if correct==16:
        return times
    if times > 48 or index>9:
        return 100
    for i in range(0,4):
        cur = changeClock(index, cur, i)
        ret = min(ret, setOClock(times+i,index+1,cur))
        cur = backClock(index,cur,i)
    return ret




if __name__=="__main__":
    clock = [12,9,3,12,6,6,9,3,12,9,12,9,12,12,6,6]
    res = setOClock(0,0,clock)
    print(res)
