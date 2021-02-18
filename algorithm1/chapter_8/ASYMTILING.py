def tiling(n):
    if n <= 1:
        return 1
    if (cache[n] != -1):
        return cache[n]
    cache[n] = tiling(n-1)+tiling(n-2)
    return cache[n]

def asymtiling(n):
    if (n%2==0):
        return tiling(n) - tiling(n/2-1) - tiling(n/2)
    else:
        return tiling(n) - tiling((n-1)/2)

def asymtiling2(n):
    if n <= 2:
        return 0
    if cache2[n] != -1:
        return cache2[n]
    cache2[n] = asymtiling2(n-2)
    cache2[n] = cache2[n]+asymtiling2(n-4)
    cache2[n] = cache2[n]+tiling(n-3)
    cache2[n] = cache2[n]+tiling(n-3)
    return cache2[n]
if __name__=="__main__":
    cache = [-1]*101
    cache2 = [-1]*101
    ret = asymtiling2(92)%1000000007
    print(ret)