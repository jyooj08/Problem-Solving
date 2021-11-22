import heapq

def solution(n, edge):
    graph = []
    dist = [50000]*(n+1)
    heap = []
    dist[0] = -1
    
    for i in range(n+1):
        graph.append([])
    
    for e in edge:
        graph[e[0]].append(e[1])
        graph[e[1]].append(e[0])
    # print(graph)
    # print(dist)
    
    heapq.heappush(heap, 1)
    dist[1] = 0
    while heap:
        node = heapq.heappop(heap)
        for x in graph[node]:
            # print(node, x)
            if dist[x] > dist[node] + 1:
                dist[x] = dist[node] + 1
                heapq.heappush(heap, x)
            # print(node, heap, dist)
    
    max_dist = max(dist)
    count = 0
    for d in dist:
        if d == max_dist: count+=1
    
    return count