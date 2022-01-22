import heapq as h

def solution(maps):
    answer = -1
    MAX = 10000
    n, m = len(maps), len(maps[0])
    dists = [[MAX for i in range(m)] for j in range(n)]
    heap = []
    
    dists[0][0] = 0
    h.heappush(heap, (1, 0, 0))
    
    while heap:
        d, x, y = h.heappop(heap)
        # print('current:', d, x, y)
        maps[x][y] = 2
        
        if x-1 >= 0 and maps[x-1][y] == 1 and d+1 < dists[x-1][y]:
            dists[x-1][y] = d+1
            h.heappush(heap, (d+1, x-1, y))
        if x+1 < n and maps[x+1][y] == 1 and d+1 < dists[x+1][y]:
            dists[x+1][y] = d+1
            h.heappush(heap, (d+1, x+1, y))
        if y-1 >= 0 and maps[x][y-1] == 1 and d+1 < dists[x][y-1]:
            dists[x][y-1] = d+1
            h.heappush(heap, (d+1, x, y-1))
        if y+1 < m and maps[x][y+1] == 1 and d+1 < dists[x][y+1]:
            dists[x][y+1] = d+1
            h.heappush(heap, (d+1, x, y+1))
        # print(heap, end='\n')
        
    if dists[n-1][m-1] != MAX:
        answer = dists[n-1][m-1]
    return answer