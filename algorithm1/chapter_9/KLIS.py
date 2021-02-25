def lis(idx): #현재 idx로부터 시작해서 구할 수 있는 최대 길이
    if idx>=len(nums):
        return 0
    if cacheLen[idx] != -1:
        return cacheLen[idx]
    cacheLen[idx] = 1
    ret = 1
    for i in range(idx+1, len(nums)):
        if nums[idx]<nums[i]:
            cacheLen[idx] = max(cacheLen[idx], 1+lis(i))
    return cacheLen[idx]

def count(idx):
    if idx>=len(nums):
        return 0
    if cacheLen[idx] == 1:
        cacheCnt[idx] = 1
        return 1
    if cacheCnt[idx] != -1:
        return cacheCnt[idx]
    cacheCnt[idx] = 0
    for i in range(idx+1, len(nums)):
        if nums[idx]<nums[i] and cacheLen[idx] - cacheLen[i] == 1:
            cacheCnt[idx] = cacheCnt[idx] + count(i)
    return cacheCnt[idx]
def KLIS(idx,skip):
    if idx>=len(nums):
        return
    
    nexts = []
    for i in range(idx+1, len(nums)):
        if cacheLen[idx]-cacheLen[i] == 1 and nums[idx]<nums[i]:
            nexts.append(nums[i])
    nexts.sort()
    for i in nexts:
        pos = nums.index(i)
        if cacheCnt[pos] < skip:
            skip = skip - cacheCnt[pos]
        else:
            part.append(nums[pos])
            return KLIS(pos,skip)
    return

if __name__=="__main__":
    nums = [-1,2,1,4,3,6,5,8,7]
    cacheLen = [-1]*(len(nums))
    cacheCnt = [-1]*(len(nums))
    skip = 6
    part = []
    ret = lis(0)-1
    count = count(0)
    reconstruct = KLIS(0,4)
    print(count)
    print(cacheCnt)
    print(part)