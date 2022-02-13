# def solution(k, dungeons):
#     answer = 0
#     dungeons.sort(key = lambda x: (x[1]-x[0]))
    
#     for d in dungeons:
#         if k >= d[0]:
#             k -= d[1]
#             answer += 1
#     return answer

import itertools

def solution(k, dungeons):
    answer = 0
    idx = [i for i in range(len(dungeons))]
    total_idx = list(itertools.permutations(idx))
    
    for x in total_idx:
        a, _k = 0, k
        for i in x:
            if _k >= dungeons[i][0]:
                _k -= dungeons[i][1]
                a += 1
        if a > answer:
            answer = a
        
    return answer