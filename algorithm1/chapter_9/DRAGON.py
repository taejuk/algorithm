'''
def evolve(begin, generation):
    if p <= len(begin):
        return begin[p-1]
    if generation == 0:
        return begin
    newbegin = ''
    for i in range(0, len(begin)):
        if begin[i] == 'X':
            newbegin = newbegin + 'X+YF'
        elif begin[i] == 'Y':
            newbegin = newbegin+'FX-Y'
        else:
            newbegin = newbegin+begin[i]
    return evolve(newbegin, generation-1)
'''
def expand(dragonCurve, generations, skip):
    if generations == 0:
        return dragonCurve[skip]
    for i in range(0, len(dragonCurve)):
        if(dragonCurve[i] == 'X' or dragonCurve[i] == 'Y'):
            if(skip >= lens[generations]):
                skip = skip - lens[generations]
            elif dragonCurve[i] == 'X':
                return expand('X+YF', generations-1, skip)
            else:
                return expand('FX-Y', generations-1, skip)
        elif skip>0:
           skip = skip - 1
        else:
            return dragonCurve[i]
    return '#' 
if __name__ == "__main__":
    lens = [1]
    for i in range(1,51):
        lens.append(lens[i-1]*2+2)
    result = ''
    for i in range(0, lens[2]+1):
        result = result+expand("FX", 2, i)
    print(result)