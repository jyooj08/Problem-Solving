import heapq as h

def solution(jobs):
    time = 0
    count = len(jobs)
    jobs.sort()
    heap = []
    total = []
    
    
    while jobs or heap:
        if not heap:
            time = jobs[0][0] + jobs[0][1]
            total.append(time - jobs[0][0])
            jobs.pop(0)
            # print("not heap", time, total)
        else:
            job = h.heappop(heap)
            time += job[0]
            total.append(time - job[1])
            # print("is heap", time, total)
        
        while jobs and jobs[0][0] <= time:
            h.heappush(heap, [jobs[0][1], jobs[0][0]])
            jobs.pop(0)
        # print("heap: ", heap)
    
    return sum(total)//count