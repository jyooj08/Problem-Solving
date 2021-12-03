def maxRight(cur, n, visited):
    cur_len, max_len = 0, 0
    idx = cur + 1
    if idx >= n: idx = 0
    while idx != cur:
        cur_len += 1
        if visited[idx] == False:
            max_len = cur_len
        idx += 1
        if idx >= n: idx = 0
            
    return max_len

def maxLeft(cur, n, visited):
    cur_len, max_len = 0, 0
    idx = cur - 1
    if idx < 0: idx = n - 1
    while idx != cur:
        cur_len += 1
        if visited[idx] == False:
            max_len = cur_len
        idx -= 1
        if idx < 0: idx = n - 1
            
    return max_len

def solution(name):
    n = len(name)
    answer = 0
    visited = [False]*n
    
    for x in name:
        answer += min(ord(x) - ord('A'), ord('Z') - ord(x) + 1)
        
    for i in range(n):
        if name[i] == 'A':
            visited[i] = True
    
    cur = 0
    while True:
        visited[cur] = True
        r = maxRight(cur, n, visited)
        l = maxLeft(cur, n, visited)
        
        if r == l == 0:
            break
        
        if r <= l:
            while visited[cur] == True:
                cur += 1
                if cur == n: cur = 0
                answer += 1
        else:
            while visited[cur] == True:
                cur -= 1
                if cur == -1: cur = n-1
                answer += 1
    return answer