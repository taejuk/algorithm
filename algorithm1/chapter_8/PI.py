def checkBalance(nums):
    check = 0
    for i in range(0, len(nums)-1):
        if nums[i] == nums[i+1]:
            check = check + 1
        else:
            break
    if check == len(nums)-1 :
        return 1
    check = 0
    for i in range(0, len(nums)-1):
        if nums[i] - nums[i+1] == 1:
            check = check + 1
        else:
            break
    if check == len(nums) - 1:
        return 2
    check = 0
    for i in range(0, len(nums)-1):
        if nums[i] - nums[i+1] == -1:
            check = check + 1
        else:
            break
    if check == len(nums) - 1:
        return 2
    
    check = 0
    for i in range(0, len(nums)-2):
        if nums[i] == nums[i+2]:
            check = check + 1
        else:
            break
    if check == len(nums) - 2:
        return 4
    
    check = 0
    for i in range(0, len(nums)-2):
        if nums[i] - nums[i+1] == nums[i+1] - nums[i+2]:
            check = check + 1
        else:
            break
    if check == len(nums) - 2:
        return 5
    
    return 10
#동적계획법 적용x
def PI(idx):
    if idx >= len(pis):
        return 0
    ret = 12345678
    for i in range(3,6):
        ret = min(ret, checkBalance(pis[idx:idx+i])+PI(idx+i))
    return ret
#동적계획법 적용o
def pi(idx):
    if idx >= len(pis):
        return 0
    if cache[idx] != 12345678:
        return cache[idx]
    
    for i in range(3,6):
        cache[idx] = min(cache[idx], checkBalance(pis[idx:idx+i])+pi(idx+i))
    return cache[idx]

if __name__=="__main__":
    pis = [1,2,6,7,3,9,3,9]
    cache = [12345678]*len(pis)
    ret = pi(0)
    print(ret)