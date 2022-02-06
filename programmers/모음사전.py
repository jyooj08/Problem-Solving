num = {'A': 1, 'E': 2, 'I': 3, 'O': 4, 'U': 5}
arr = [0, 5, 30, 155, 780]

def solution(word):
    answer = 0
    length = len(word)
    
    for idx, ch in enumerate(word):
        total = num[ch] + (num[ch] - 1) * arr[4-idx]
        # print(idx, ch, arr[4-idx], num[ch], total)
        answer += total
    
    return answer