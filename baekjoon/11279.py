import heapq as h
from sys import stdin

n = int(stdin.readline())
heap = []

for i in range(n):
    x = int(stdin.readline())
    if x == 0:
        if heap: print(h.heappop(heap)[1])
        else: print(0)
    else:
        h.heappush(heap, (-x, x))