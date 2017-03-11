import sys
# sys.stdin = open("input.txt")

dp = [0 for i in range(5001)]
dp[0]=1
for i in range(1, 5001):
    dp[i] = (4*i-2)*dp[i-1]//(i+1)

# main
q = int(input())
for i in range(q):
    n = int(input())
    print(dp[n])
