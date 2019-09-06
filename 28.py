# This problem is really dumb

size = 1001
result = (size - 1)//2 * 4 + 1
base = 0
for i in range(1, (size - 1)//2 + 1):
    gap = i*2
    for j in range(1, 4 + 1):
        base += gap
        result += base

print(result)
