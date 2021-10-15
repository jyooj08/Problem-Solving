import datetime

def solution(lines):
    max_count = 0
    time2 = []
    time3 = []
    
    for x in lines:
        x = x.split()
        t1 = datetime.datetime.strptime(x[0]+' '+x[1], "%Y-%m-%d %H:%M:%S.%f")
        t2 = t1 + datetime.timedelta(seconds=0.999)
        t3 = t1 + datetime.timedelta(seconds= -float(x[2][:-1])+0.001)
        #print(t2, t3)
        time2.append(t2)
        time3.append(t3)
        
    for i, x in enumerate(time2):
        cnt = 0
        for j, y in enumerate(time3):
            if i > j:
                continue
            #print(x, y)
            if x >= y:
                cnt += 1
        max_count = max(cnt, max_count)
    
    return max_count