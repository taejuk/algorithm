def poly(n, floor):
    if n==0:
        return 1
    if n == floor:
        return 1
    if (cache[n][floor] != -1):
        return cache[n][floor]
    cache[n][floor] = 0
    for next_floor in range(1, n-floor+1):
        cache[n][floor] = cache[n][floor]+(floor+next_floor-1)*poly(n-floor, next_floor)
    return cache[n][floor]




if __name__=="__main__":
    cache = [[-1]*101 for i in range(1,101)]
    ret = 0
    for i in range(1,93):
        ret = ret + poly(92, i)
    print(ret%10000000)