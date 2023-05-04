from collections import deque

def BFS(N,K):
  queue = deque([N])
  time = 0 # 시간을 세주는 변수
  visited[N] = 0 # 시작점은 시간이 0임
  count = 0 # 몇 가지인지 세어주는 변수
  result = 1000000 # 최솟값을 갱신해주기 위한 변수

  while queue:
    size = len(queue) 
    time += 1 

    for _ in range(size):# 각 경우에 대해 시간 별로 맞춰서 찾아야 함
      n = queue.popleft()
      if(n == K): # K에 도달했을 때 최솟값인지 아닌지 판단
        if(visited[K] > result): # 최솟값 X
          continue 
        elif(visited[K] < result): # 최솟값임
          result = visited[K] #최솟값을 저장하고 다음 값이 왔을 때 비교
          count = 1
        else: # 최솟값이 여러 개일 때
          count += 1
        continue
      # 0보다 크거나 같아야하고 원래 있던 값보다 최솟값이면 값을 갱신
      if(n-1 >= 0 and (visited[n-1] == None or visited[n-1] > visited[n])):
        queue.append(n-1)
        visited[n-1] = time
      # 100,000보다 작거나 같아야하고 원래 있던 값보다 최솟값이면 값을 갱신
      if(n+1 <= 100000 and (visited[n+1] == None or visited[n+1] > visited[n])):
        queue.append(n+1)
        visited[n+1] = time
      if(n*2 <= 100000 and (visited[n*2] == None or visited[n*2] > visited[n])):
        queue.append(n*2)
        visited[n*2] = time
        
  print(result)
  print(count)

N , K = map(int,input().split())
visited = [None] * 100001

BFS(N,K)

