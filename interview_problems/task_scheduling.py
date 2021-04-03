from collections import defaultdict 
lst = ['abc', 'bcd', 'cde', 'def']

def solve(arr):
    res = {}
    # def dzero():
    #     return 0
    # def zero():
    #     return defaultdict(dzero)
    mapping = {}

    for s in arr:
        for i in range(len(s)):
            c = s[i] # a 
            for j in range(len(s)):
                if i == j:
                    continue 
                if c in mapping and s[j] in mapping[c]:
                    mapping[c][s[j]] += 1
                else:
                    temp = {}
                    temp[s[j]] = 1
                    mapping[c] = temp
    print(len(mapping))
    print(mapping[0])
    for k, v in mapping:
        res[k] = []
        if len(v) == 0:
            continue
        sortedValues = sorted(v, key = lambda x : x[1], reverse=True)
        maxValue = sortedValues[0][1]
        for val in sortedValues:
            if val[1] == maxValue:
                res[k].append(val[0])
    return res

print(solve(lst))

