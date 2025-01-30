import bisect
n=int(input())
a = [-0x7fffffff,0x7fffffff]
for _ in range(n):
    op, num = list(map(int, input().split()))
    if op==1:
        idx = bisect.bisect_left(a, num)
        print(idx)
    elif op==2:
        print(a[num])

    elif op == 3:# 前驱
        idx = bisect.bisect_left(a, num)  # 貌似包括自己
        idx -= 1
        # if a[idx]==num:
        print(a[idx])
        # print("idx:{}, val:{}".format(idx, a[idx]))

    elif op == 4:
        idx = bisect.bisect_right(a, num)
        print(a[idx])
    else:
        bisect.insort(a, num)



"""
7
5 1
5 3
5 5
1 3
2 2
3 3
4 3
//x不在 
7
5 1
5 3
5 5
1 4
2 2
3 3
4 3

7
5 1
5 3
5 5
1 2
2 2
3 3
4 3

7
5 1
5 3
5 5
1 5
2 2
3 3
4 3
//前后驱
7
5 1
5 3
5 5
1 1
2 2
3 1
4 5 

7
5 1
5 3
5 5
1 3
2 1
3 3
4 3

7
5 1
5 2
5 5
1 3
2 2
3 3
4 3
"""