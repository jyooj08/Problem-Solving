def checkWord(used, word):
    if not used:
        return True
    if used[-1][-1] != word[0]:
        return False
    if word in used:
        return False
    if len(word) == 1:
        return False
    return True

def solution(n, words):
    used = []
    stop = -1
    
    for idx, word in enumerate(words):
        if checkWord(used, word):
            used.append(word)
        else:
            stop = idx
            break
    
    if stop == -1:
        return [0, 0]
    else:
        return [stop%n+1, stop//n+1]