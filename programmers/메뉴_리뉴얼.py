import itertools

def solution(orders, course):
    answer = []
    
    for c in course:
        comb = []
        count = {}
        for o in orders:
            comb.extend(list(itertools.combinations(o, c)))
            
        for x in comb:
            s = "".join(sorted("".join(x)))
            try: count[s] += 1
            except: count[s] = 1
        if not count:
            continue
        max_count = max(count.values())
        
        for k, v in count.items():
            if v == max_count and v >= 2:
                answer.append(k)
        
    answer.sort()
    return answer