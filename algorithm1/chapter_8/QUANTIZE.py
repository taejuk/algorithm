def calc(nums):
    total = 0
    for i in nums:
        total = total + i
    aver = int(total/len(nums))
    res = 0
    for i in nums:
        res = res + (i - aver)*(i - aver)
    res2 = 0
    aver = aver + 1
    for i in nums:
        res2 = res2 + (i - aver)*(i - aver)
    return min(res, res2)

def quantize(idx, s):
    if idx>= len(quantums):
        return 0
    if s == 1:
        cache[idx][s] = min(calc(quantums[idx:]), cache[idx][s])
        return cache[idx][s]
    if cache[idx][s] != 987654321:
        return cache[idx][s]
    
    for i in range(1, len(quantums[idx:])-s+2):
        cache[idx][s] = min(calc(quantums[idx:idx+i])+ quantize(idx+i,s-1),cache[idx][s])
    return cache[idx][s]

if __name__=="__main__":
    quantums = [1,4,6,744,755,777,890,897,902]
    cache = [[987654321]*4 for i in range(0,len(quantums))]
    ret = quantize(0, 3)
    print(ret)