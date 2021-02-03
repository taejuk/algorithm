def fence(height, start, end):
    if(start == end):
        return height[start]
    mid = int((start+end)/2)
    ret = max(fence(height,start,mid), fence(height, mid+1,end))
    lo = mid
    hi = mid+1
    h = min(height[lo], height[hi])
    ret = max(ret, h*2)
    while(start < lo or hi < end):
        if(hi<end) and ((lo == start) or (height[lo-1]<height[hi+1])):
            hi = hi+1
            h = min(h, height[hi])
        else:
            lo = lo-1
            h = min(h, height[lo])
        ret = max(ret, h*(hi-lo+1))
    return ret

if __name__=="__main__":
    height = [7,1,5,9,6,7,3]
    res = fence(height, 0, 6)
    print(res)