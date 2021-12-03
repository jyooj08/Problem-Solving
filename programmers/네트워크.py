def dfs(start, visited, computers):
    visited[start] = True
    for i, x in enumerate(computers[start]):
        if i == start: continue
        if x == 1 and visited[i] == False:
            dfs(i, visited, computers)

def solution(n, computers):
    count = 0
    visited = [False] * n
    
    while True:
        start = -1
        for i in range(n):
            if visited[i] == False:
                start = i
                break
        if start == -1:
            break
        dfs(start, visited, computers)
        count += 1
    
    return count