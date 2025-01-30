from collections import deque
a = [0] * int(1e5+5)
s = set()
q = deque()
n = int(input())
maxLen = 86400
for _ in range(n):
    data = list(map(int, input().split()))
    t,m = data[0],data[1]
    data.pop(0),data.pop(0)
    while q and t - q[0]['t'] >= maxLen:
        a[q[0]['id']] -=1
        if a[q[0]['id']]==0:
            s.discard(q[0]['id'])
        q.popleft()
    for i in range(m):
        q.append({'id':data[i],'t':t})
        if a[data[i]]==0:
            s.add(data[i])
        a[data[i]]+=1
    print(len(s))

'''
4
1 4 1 2 2 3
3 2 2 3
86401 2 3 4
86402 1 5
'''