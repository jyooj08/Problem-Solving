def solution(N, number):
    answer = -1
    n = N
    arr = [0, [N]]
    
    if N == number: return 1
    
    for i in range(2, 9):
        tmp = [int(str(N)*i)]
        
        for j in range(1, i//2+1):
            # print("i:", i, "j: ",j)
            for x in arr[j]:
                for y in arr[i-j]:
                    tmp.append(x+y)
                    tmp.append(x-y)
                    tmp.append(y-x)
                    tmp.append(x*y)
                    if y != 0: tmp.append(x//y)
                    if x != 0: tmp.append(y//x)
        
        if number in tmp:
            answer = i
            break
        arr.append(list(set(tmp)))
    
    return answer