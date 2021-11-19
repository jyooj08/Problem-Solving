def findPath(place, start, end):
    if start[0] == end[0]:
        if place[start[0]][int((start[1]+end[1])/2)] == 'X':
            return False
        else: return True
    if start[1] == end[1]:
        if place[int((start[0]+end[0])/2)][start[1]] == 'X':
            return False
        else: return True
        
    x = min(start[0], end[0])
    y = min(start[1], end[1])
    count = 0
    # print(start, end, x, y)
    if place[x][y] == 'X': count += 1
    if place[x+1][y] == 'X': count += 1
    if place[x][y+1] == 'X': count += 1
    if place[x+1][y+1] == 'X': count += 1
    if count == 2:
        # print(3)
        return False
    # print(4)
    return True
        

def solution(places):
    answer = []
    
    for place in places:
        # print('place')
        pos = []
        for i in range(5):
            for j in range(5):
                if place[i][j] == 'P':
                    pos.append((i, j))
        # print(pos)

        find = False
        for i in range(len(pos)-1):
            for j in range(i+1, len(pos)):
                dist = abs(pos[i][0]-pos[j][0])+abs(pos[i][1]-pos[j][1])
                if dist < 2:
                    find=True
                    break
                # print(pos[i], pos[j], dist)
                if dist == 2 and findPath(place, pos[i], pos[j]):
                    find = True
                    break

        if find: answer.append(0)
        else: answer.append(1)
                
    
    return answer