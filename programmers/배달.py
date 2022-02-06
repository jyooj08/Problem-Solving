import heapq as h

def solution(N, road, K):
    MAX = 1000000
    dist = [MAX] * (N + 1)
    graph = [[] for i in range(N + 1)]
    
    
    for a, b, c in road:
        graph[a].append((b, c)) # next, cost
        graph[b].append((a, c))
    
    
    heap = [(0, 1)] # cost, next
    dist[1] = 0
    while heap:
        cur_cost, cur_node = h.heappop(heap)
        for next_node, edge_cost in graph[cur_node]:
            if dist[next_node] > cur_cost + edge_cost:
                dist[next_node] = cur_cost + edge_cost
                h.heappush(heap, (dist[next_node], next_node))
    
    answer = 0
    for d in dist:
        if d <= K: answer += 1
        
    return answer