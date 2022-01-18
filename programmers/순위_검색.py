from itertools import product, combinations

def lowerBound(arr, l, r, key):
    while l < r:
        m = (l+r) // 2
        if arr[m] < key: l = m+1
        else: r = m
    return r

def solution(info, query):
    answer = []
    table = {}
    
    for x in info:
        x = x.split()
        score = int(x[4])
        conds = [[x[0], '-'], [x[1], '-'], [x[2], '-'], [x[3], '-']]
        for c in list(product(*conds)):
            key = c[0]+c[1]+c[2]+c[3]
            if key in table: table[key].append(score)
            else: table[key] = [score]
    
    for key in table:
        table[key].sort()
    
    for q in query:
        q = q.replace('and', '').split()
        score = int(q[4])
        q = q[0]+q[1]+q[2]+q[3]
        if q in table:
            length = len(table[q])
            answer.append(length-lowerBound(table[q], 0, length, score))
        else:
            answer.append(0)
    return answer