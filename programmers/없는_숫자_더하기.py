def solution(numbers):
    answer = 0
    exist = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    
    for n in numbers:
        exist[n] = 1;
    
    for i, e in enumerate(exist):
        if e == 0:
            answer += i
    return answer