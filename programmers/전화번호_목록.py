def solution(phone_book):
    answer = True
    
    phone_book.sort()
    count = len(phone_book)
    
    for i in range(count-1):
        if phone_book[i+1].startswith(phone_book[i]):
            return False
    return True