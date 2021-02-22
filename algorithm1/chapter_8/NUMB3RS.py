def findPath(cur):
    ret = []
    for i in range(len(path)):
        if path[cur][i] == 1:
            ret.append(i)
    return ret


#동적 계획법 적용x
def numb3rs(day, per):
    if day == 2:
        return per
    newper = [0]*5
    for i in range(len(path)):
        if per[i] >0:
            paths = findPath(i)
            totals = len(paths)
            for j in paths:
                newper[j] += float(per[i])/totals

    return numb3rs(day+1, newper)

#동적 계획법 적용o
def numb3rs2(day, cur):
    #끝나는 조건
    if day == 0:
        if cur == 0:
            cache[day][cur] = 1
            return 1
        else:
            cache[day][cur] = 0
            return 0
    if cache[day][cur] != -1:
        return cache[day][cur]
    cache[day][cur] = 0
    paths = findPath(cur)
    for i in paths:
        cache[day][cur] = cache[day][cur] + numb3rs2(day-1, i) / float(total_paths[i])
    return cache[day][cur]
    
    


if __name__=="__main__":
    path = [[0,1,1,1,0],[1,0,0,0,1],[1,0,0,0,0],[1,0,0,0,0],[0,1,0,0,0]]
    total_paths = []
    for i in path:
        total = 0
        for j in i:
            total = total + j
        total_paths.append(total)
    print(total_paths)
    cache = [[-1]*10 for i in range(0,10)]

    percentage = [1,0,0,0,0]
    ret = numb3rs2(2,4)
    print(ret)