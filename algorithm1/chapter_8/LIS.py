def LIS(x):
    if (x == 4):
        cache[4] = [nums[4]]
        return cache[4]
    if (len(cache[x])!=0):
        return cache[x]
    cache[x] = [nums[x]] #초기화
    temp = []
    for i in range(x+1, len(nums)):
        if(nums[x]<nums[i]):
            temp_result = LIS(i)
            if (len(temp)<len(temp_result)):
                temp = temp_result
    cache[x] = cache[x] + temp
    return cache[x]
    


if __name__=="__main__":
    nums = [1,5,2,4,7]
    cache = [[],[],[],[],[]]
    ret = LIS(0)
    print(ret)