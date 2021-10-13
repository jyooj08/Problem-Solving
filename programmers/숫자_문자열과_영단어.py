def solution(s):
    nums = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
    words = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
    
    for i in range(10):
        s = s.replace(words[i], nums[i])
    
    return int(s)