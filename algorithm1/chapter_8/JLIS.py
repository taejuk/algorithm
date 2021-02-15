#동적계획법 적용x
def JLIS(idx_a, idx_b, mins):
    if(idx_a == len(a) and idx_b == len(b)):
        if a[idx_a]<mins and b[idx_b]<mins:
            return 0
        elif a[idx_a] >= mins and b[idx_b] >= mins and a[idx_a]!=b[idx_b]:
            return 2
        else:
            return 1
    ret = 1
    for i in range(idx_a, len(a)):
        for j in range(idx_b,len(b)):
            if mins < a[i]:
                ret = max(ret, 1+JLIS(i,j,a[i]))
            if mins < b[j]:
                ret = max(ret, 1+JLIS(i,j,b[j]))
    return ret
    
#동적계획법 적용o
def jlis(idx_a, idx_b):
    if cache[idx_a+1][idx_b+1] != -1:
        return cache[idx_a+1][idx_b+1]
    cache[idx_a+1][idx_b+1] = 2
    temp_a = 0
    temp_b = 0
    if idx_a == -1:
        temp_a = -100
    else:
        temp_a = a[idx_a]
    if idx_b == -1:
        temp_b = -100
    else:
        temp_b = b[idx_b]
    mins = max(temp_a, temp_b)
    
    for i in range(idx_a+1, len(a)):
        if mins<a[i]:
            cache[idx_a+1][idx_b+1] = max(cache[idx_a+1][idx_b+1], 1+ jlis(i, idx_b))
    for i in range(idx_b+1, len(b)):
        if mins<b[i]:
            cache[idx_a+1][idx_b+1] = max(cache[idx_a+1][idx_b+1], 1+ jlis(idx_a,i))
    return cache[idx_a+1][idx_b+1]
    

if __name__=="__main__":
    a = [1,2,4]
    b = [3,4,7]
    cache = [[-1]*10 for j in range(10)]
    ret = jlis(-1,-1)
    print(ret-2)
    
