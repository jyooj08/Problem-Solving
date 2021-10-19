def solution(str1, str2):
    str1 = str1.upper()
    str2 = str2.upper()
    print(str1, str2)
    
    # 두 글자씩 끊기 & 특수문자 버리기
    set1, set2 = [], []
    
    while str1 != "":
        tmp = str1[0:2]
        str1 = str1[1:]
        if tmp.isalpha() and len(tmp)==2: set1.append(tmp)
            
    while str2 != "":
        tmp = str2[0:2]
        str2 = str2[1:]
        if tmp.isalpha() and len(tmp)==2: set2.append(tmp)
    
    # 교집합 구하기
    common = []
    for x in set1:
        if x in set2:
            common.append(x)
            set2.remove(x)
    
    # 합집합 구하기
    union = set1 + set2
    for x in common:
        union.remove(x)
    union = union + common
    
    # 유사도 구하기
    n1 = len(common)
    n2 = len(union)
    ratio = n1 / n2 if n2 != 0 else 1
    
    return int(ratio * 65536)