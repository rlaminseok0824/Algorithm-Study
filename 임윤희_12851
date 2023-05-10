from collections import deque

N, K = map(int, input().split())

def bfs(n): 
    queue = deque()
    queue.append(n)
    time = [0 for _ in range(100001)]
    K_lst = []
    cnt = 1
    min = float("inf")

    # 수빈과 동생 위치가 같은 경우
    if(N == K):
        min = 0
        return min, cnt

    while queue:
        x = queue.popleft()
        print(x)
        # 세 가지 경우
        dx = [-1, 1, x]
        
        for i in range(3):
            nx = x + dx[i]
            if nx <= -1 or nx >= 100001:
                continue       
                        

            # 값이 작다면 큐에 다시 추가해라.
            # 어쩔때 K에 추가하는지 고려해라.


            # 시간 증가
            if(nx == K): # 동생 찾은 경우
                if(time[x]+1 < time[K]):
                    min = time[x]+1
                    queue.append(nx)
                    cnt = 1
            
                elif(time[x]+1 == min):
                   cnt += 1
                else:
                    return time[K], cnt

            else: # 동생 못 찾은 경우
                time[nx] = time[x] + 1
                queue.append(nx)


    return time[K], cnt
           
print(bfs(N))












# # 방법 개수 세기
# if N == K:
#     method = 1
# # 동생 찾기 1초 전인 경우 탐색
# elif (min_time == 1):
#         # 걷는 경우
#         if (N == K - 1) or (N == K + 1):
#             method += 1

#         # 동생 위치가 짝수일 때 순간이동 하는 경우
#         if (K % 2 == 0) and (K != 0) and (N == K / 2):
#             method += 1
# else:
#     method = 0
#     for idx in range(len(time)):
#             if time[idx] == (min_time - 1):

#                 # 걷는 경우
#                 if (idx == K - 1) or (idx == K + 1):
#                     method += 1

#                 # 동생 위치가 짝수일 때 순간이동 하는 경우
#                 if (K % 2 == 0) and (K != 0) and (idx == K / 2):
#                     method += 1

