'''
def ZIMBABWE(cur, used,digits):
    finished = 0
    for i in used:
        finished = finished + i
    if finished == 0:
        if(cur % m == 0 and cur<12738173912):
            return 1
        else:
            return 0
    res = 0
    for i in range(0, 10):
        if used[i] != 0:
            cur = cur + i*pow(10, digits)
            used[i] = used[i] - 1
            res = res + ZIMBABWE(cur, used, digits-1)
            used[i] = used[i] + 1
            cur = cur - i*pow(10, digits)
    return res
'''
def generate(price, taken):
    if (len(price) == n):
        if price < e:
            print(price)
    for i in range(0, n):
        if (taken[i]==False and (i == 0 or digits[i-1] != digits[i] or taken[i-1] == True)):
            taken[i] = True
            generate(price+digits[i], taken)
            taken[i] = False

def price(index, taken, mod, less):
    if (index == n):
        if mod == 0 and less == 1:
            return 1
        else:
            return 0
    if(cache[taken][mod][less] != -1):
        return cache[taken][mod][less]
    cache[taken][mod][less] = 0
    for next in range(0, n):
        if((taken&(1<<next)) == 0):
            continue
        if next>0 and digits[next] == digits[next-1] and (taken&(1<<(next-1)) ==0):
            continue
        nextTaken = taken | (1<<next)
        nextMod = (mod*10 + digits[next]-'0') % m
        if less or e[index]>digits[next]:
            nextLess = 1
        else:
            nextLess = 0
        cache[taken][mod][less] += price(index+1, nextTaken, nextMod, nextLess)
    return cache[taken][mod][less]


if __name__=="__main__":
    e = '12738173912'
    digit = list(e)
    digit = list(map(int, e))
    digit.sort()
    digits = ''
    cache = 1
    for i in digit:
        digits = digits + str(i)
    m = 7
    n = len(e)
    taken = [False]*15
    cache[1<<14][20][2]