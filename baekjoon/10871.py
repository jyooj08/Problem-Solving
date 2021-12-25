nx = input()
arr = input().split()
x = int(nx.split()[1])

for num in arr:
    if int(num) < x:
        print(num, end=' ')