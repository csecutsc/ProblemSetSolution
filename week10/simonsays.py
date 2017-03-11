times = int(input())

for i in range (times):
    s = input()
    s = s.split()
    if s[0] == 'Simon' and s[1] == 'says':
        answer = ''
        for i in range(2, len(s)):
            answer += (s[i] + ' ')
        print (answer)