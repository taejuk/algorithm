def match(word, standard):
    ret = False
    idx = 0
    while idx<len(word):
        if word[idx] == '*':
            break
        elif (word[idx] == '?') or (word[idx]==standard[idx]):
            idx = idx + 1
        elif (word[idx] != standard[idx]):
            return False
    if idx == len(word):
        return True
    if idx == len(word)-1 and word[idx] == '*':
        return True
    next_word = word[idx+1]
    for i in range(idx, len(standard)):
        if standard[i] == next_word and ret==False:
            ret = match(word[idx+1:], standard[i:])
    return ret

def matchMemoized(w, s):
    if(cache[w][s]!=-1):
        return cache[w][s]
    while s < len(S) and w < len(W) and (W[w] == '?' or W[w] == S[s]): #일치하는 글자 다 찾기
        w = w+1
        s = s+1
    if(w == len(w)):
        if s == len(S):
            cache[w][s] = 1
        else:
            cache[w][s] = 0
        return cache[w][s]
    if(W[w] == '*'):
        for skip in range(0, len(S) - s +1):
            if(matchMemoized(w+1, s + skip)):
                cache[w][s] = 1
                return 1
    cache[w][s] = 0
    return 0
    
if __name__=="__main__":
    ret = match(0,0)
    print(ret)