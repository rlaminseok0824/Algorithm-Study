import sys
input = sys.stdin.readline

# 입력
N = int(input().strip())
A = list(map(int, input().split()))

dp = [i for i in range(len(A))]
dp[0] = 1

for i in range(1, len(A)):
    for j in range(i):
        if A[i] < A[j]:
            dp[i] = dp[j] + 1

print(max(dp))
# print(dp)