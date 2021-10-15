import heapq

def solution(scoville, K):
    answer = 0
    heap = []
    for x in scoville:
        heapq.heappush(heap, x)
    
    while True:
        if not heap or heap[0] >= K:
            break
        
        if len(heap) < 2:
            answer = -1
            break
        
        first = heapq.heappop(heap)
        second = heapq.heappop(heap)
        heapq.heappush(heap, first + second * 2)
        answer += 1
    return answer