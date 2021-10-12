def solution(scores):
    answer = ''
    size = len(scores)
    new_scores = []
    avgs = []
    
    for i in range(size):
        new_scores.append([])
        for j in range(size):
            new_scores[i].append(scores[j][i])
    
    for i in range(size):
        me = new_scores[i][i]
        if me == min(new_scores[i]) or me == max(new_scores[i]):
            if new_scores[i].count(me) == 1:
                del new_scores[i][i]
        avgs.append(sum(new_scores[i]) / len(new_scores[i]))
        
    for a in avgs:
        if a >= 90:
            answer += 'A'
        elif a >= 80:
            answer += 'B'
        elif a >= 70:
            answer += 'C'
        elif a>= 50:
            answer += 'D'
        else:
            answer += 'F'
    return answer