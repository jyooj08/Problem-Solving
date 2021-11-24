n = int(input());
arr = list(map(int, input().split(' ')))
sorted_arr = list(set(arr))
sorted_arr.sort()

d = {}
for i, num in enumerate(sorted_arr):
    d[num] = i;

for num in arr:
    print(d[num], end=' ')
