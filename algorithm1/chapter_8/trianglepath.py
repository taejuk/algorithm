def findPath(x,y):
    if (x==4):
        cache[x][y] = path[x][y]
        return path[x][y]
    if(cache[x][y] != -1):
        return cache[x][y]
    cache[x][y] = path[x][y]

    cache[x][y] = cache[x][y] + max(findPath(x+1,y),findPath(x+1,y+1))
    return cache[x][y]


if __name__=="__main__":
    path = [[6],[1,2],[3,7,4],[9,4,1,7],[2,7,5,9,4]]
    cache = [[-1],[-1,-1],[-1,-1,-1],[-1,-1,-1,-1],[-1,-1,-1,-1,-1]]
    ret = findPath(0,0)
    print(ret)