T = int(input())

for i in range(T):
    N = int(input())
    people = {}
    holder = []
    for j in range(N):
        value = ""
        line = input()
        name, classes = line.split(":")

        classes = classes.split()
        classes = classes[0]

        classes = classes.split("-")

        for k in range(len(classes)-1, -1, -1):
            if classes[k] == "upper":
                value += "3"
            elif classes[k] == "middle":
                value += "2"
            elif classes[k] == "lower":
                value += "1"

        for l in range(len(value), 10):
            value += "2"

        value = int(value)

        if value in people:
            people[value].append(name)
        else:
            people[value] = [name]
        holder.append(value)

    holder = set(holder)
    holder = list(holder)
    holder.sort(reverse = True)
    for m in holder:
        if type(people[m])== list:
            people[m].sort()
            for n in people[m]:
                print (n)
        else:
            print (people[m])
    print ("==============================")