import bisect
n = int(input())
sumVal = 0
s = [-1e8+5,1e8+5]
for i in range(n):
    cur = int(input())
    if i==0:
        sumVal+=cur
    else:
        p = bisect.bisect_left(s,cur)  # x是下界
        if s[p]==cur:
            continue
        else:
            sumVal += min(s[p]-cur, cur-s[p-1])
    bisect.insort(s, cur)
print(sumVal)

"""
6
5
1
2
5
4
6
"""