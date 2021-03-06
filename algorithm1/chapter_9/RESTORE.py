#현재 단어가 cur이고 지금 붙어야 하는 단어가 idx일 때, 최소 길이 단어 반환
'''
def restore(cur, idx):
    if idx == n:
        print(cur)
        return
    if idx == 0:
        return restore(words[idx], idx+1)
    length = len(cur)
    tempcur = cur+ words[idx]
    for i in range(0,len(cur)):
        if cur[i] == words[idx][0]:
            remainder = length - i
            if remainder >= len(words[idx]):
                if cur[i:i+len(words[idx])] == words[idx]:
                    return restore(cur, idx+1)
            if cur[i:] == words[idx][0:len(cur[i:])]:
                newcur = cur[:i]+words[idx]
                if (len(tempcur)> len(newcur)):
                    tempcur = newcur
        if cur[i] == words[idx][-1]:
            if cur[:i+1] == words[idx][-i-1:]:
                newcur = words[idx][:-i-1]+cur
                if (len(tempcur) > len(newcur)):
                    tempcur = newcur
    return restore(tempcur,idx+1)            
'''

def restore(last, used):
    if used == (1<<n)-1:
        return 0
    if cache[last][used] != 0:
        return cache[last][used]
    cache[last][used] = 0
    for i in range(0, len(words)):
        if used&(1<<next) == 0:
            cand = overlap[last][next] + restore(next, used + (1<<next))
            cache[last][used] = max(cache[last][used], cand)
    return ret

def reconstruct(last, used):
    if used == (1<<n)-1:
        return ""
    for next in range(0,n):
        if used & (1<<next):
            ifUsed = reconstruct(next, used+ (1<<k))+overlap[last][next]
            if ifUsed == restore(last, used):
                return word[next][overlap[last][next]:] + reconstruct(next, used + (1<<next))
    return "**oops"

if __name__ == "__main__":
    words = ['abrac', 'cadabra', 'dabr']
    n = len(words)
    restore('',0)
    