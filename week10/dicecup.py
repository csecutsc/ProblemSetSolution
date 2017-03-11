N, M = input().split()
N = int(N)
M = int(M)

holder = {}

for i in range(1, N+1):
    for j in range(1, M+1):
        counter = i + j
        if counter in holder:
            holder[counter] += 1
        else:
            holder[counter] = 1


highest = 0
numbers = []
for k in holder:
    if holder[k] > highest:
        highest = holder[k]
        numbers = []
        numbers.append(k)
    elif holder[k] == highest:
        numbers.append(k)

for l in numbers:
    print (l)
