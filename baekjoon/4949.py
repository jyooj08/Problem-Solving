while True:
    sentence = input()
    if sentence == ".": break

    stack = []

    for x in sentence:
        if x in ['[', ']', '(', ')']:
            if not stack: 
                stack.append(x)
            elif stack[-1] == '[' and x == ']':
                stack.pop()
            elif stack[-1] == '(' and x == ')':
                stack.pop()
            else:
                stack.append(x)

    if stack: print('no')
    else: print('yes')