import sys
input = sys.stdin.readline

a = input().strip()

indices_of_open = []
indices_of_close = []
result=[]

def reverse(origin_str):

    indices_of_space = []

    #공백 체크
    for i in range(len(origin_str)):
        if(origin_str[i] == ' '):
            indices_of_space.append(i)

    #공백 없는 경우
    if len(indices_of_space) == 0:
        reverse_str = ''
        for c in origin_str:
            reverse_str = c + reverse_str
        result.append(reverse_str)

    #공백 있는 경우
    else:
        previous_index_of_space = 0

        # 공백 기준으로 나뉘어진 단어 별로 뒤집기
        for index_of_space in indices_of_space:
            word = ''
            for i in range(previous_index_of_space, index_of_space):
                word += origin_str[i]
            reverse_str = ''
            for c in word:
                reverse_str = c + reverse_str
            result.append(reverse_str)
            result.append(' ')
            previous_index_of_space = index_of_space+1

        #마지막 단어 뒤집기
        word = ''
        for i in range(previous_index_of_space, len(origin_str)):
            word += origin_str[i]
        reverse_str = ''
        for c in word:
            reverse_str = c + reverse_str
        result.append(reverse_str)

#---main---
#태그 체크
for i in range(len(a)):
    if(a[i] == '<'):
        indices_of_open.append(i)
    elif(a[i] == '>'):
        indices_of_close.append(i)

if len(indices_of_open) == 0: #태그가 없는 경우
    reverse(a)

else: #태그가 있는 경우
    #첫번째 태그 앞에 단어가 있는 경우
    if indices_of_open[0] != 0:
        str = a[0:indices_of_open[0]]
        reverse(str)

    previous_index_of_close = indices_of_close[0]
    for open, close in zip(indices_of_open, indices_of_close):
        str = a[previous_index_of_close+1:open]
        reverse(str)
        result.append(a[open:close+1])
        previous_index_of_close = close

    #마지막 태그 뒤에 단어가 있는 경우
    if previous_index_of_close != len(a)-1:
        str = a[previous_index_of_close+1:len(a)]
        reverse(str)
            
#결과 출력
for elem in result:
    print(elem, end='')