n = int(input())
n = 1<<n
a = []

data = list(map(int, input().split()))
for i in range(n):
    a.append({'id':i+1, 'val': data[i]})
while len(a)>2:
    size = len(a)/2
    while size:
        b = a[0]
        a.pop(0)
        c = a[0]
        a.pop(0)
        if b['val']>c['val']:
            a.append(b)
        else:
            a.append(c)
        size-=1
print(a[0]['id'] if a[0]['val']<a[1]['val'] else a[1]['id'])


"""
3
4 2 3 1 10 5 9 7
"""