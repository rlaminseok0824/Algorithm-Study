# 이번 문제는 진짜 문제를 이해를 못하겠어서 구글에 찾아봤습니다..
# 부분 수열의 의미조차 이해하지 못했습니다!

# 부분 수열: 주어진 수열의 일부 항을 원래 순서대로 나열하여 얻을 수 있는 수열
# 연속적으로 나열하지 않고 몇 개를 뛰어넘어도 부분 수열이라고 함
# 수열은 수를 늘어놓고 그것에 순번을 붙이는 것이라고 할 수 있는데,
# 규칙은 있어도 되고 없어도 된다!!

# 특정 데이터 내 최대화를 계산하는 것이므로 DP이용
#
N = int(input())  # 수열 A의크기 N을 입력
A = list(map(int, input().split()))  # 수열 A의 원소들을 입력

dp = [1]  * N # 메모이제이션을 1로 초기화를 함, 자신보다 큰 수가 없다면 자신 혼자 수열이므로 1

for i in range(N):
  for j in range(i):
    if(A[j] > A[i]): # 자신보다 큰 수가 앞에 나온다면 감소하는 수열에 속함
      dp[i] = max(dp[i], dp[j]+1) # 만약 자신보다 큰 수가 나왔지만 이것이 중복된다면,
                                  # 계속 1을 추가할 수 없으므로 최대값 비교를 함
print(max(dp))

