import sys 

class Stack: # Stack 클래스 선언
  arr = [] # 데이터를 저장하는 스택을 구현하기 위해 list 사용

  def push(self, num): 
    self.arr.append(num) 

  def pop(self):
    if(len(self.arr) == 0): # list의 길이가 0 일때
      print(-1)
    else:
      print(self.arr.pop())

  def size(self):
    print(len(self.arr))

  def empty(self):
    if(len(self.arr) == 0):
      print(1)
    else:
      print(0)
    
  def top(self):
    if(len(self.arr) == 0):
      print(-1)
    else:
      print(self.arr[-1]) # list의 마지막 값을 출력

def run(): 
  stack = Stack()
  N = int(input())

  for i in range(N):
    input_N = sys.stdin.readline().split() # 시간초과를 줄이기 위해 input()말고 sys.stdin.readline()을 사용
    # split()으로 인해 input_N의 값은 리스트 형태로 만들어지게 됨
    # split()은 공백만 처리하는 것이 아니라 \t, \n도 처리해줌/ split(" ")은 공백만 처리
    if(input_N[0] == 'push'):
      stack.push(input_N[1])
      
    elif(input_N[0] == 'pop'):
      stack.pop()
    elif(input_N[0] == 'size'):
      stack.size()
    elif(input_N[0] == 'empty'):
      stack.empty()
    elif(input_N[0] == 'top'):
      stack.top()
    else:
      return '잘못 입력하였습니다!'

run()

