m = int(input())
while m>0:
    n = int(input())
    st = []
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    i=j=0
    flag=True
    # print(a)
    while j<n:
        # print("{} {}".format(i,j))
        if i<n and a[i]==b[j]:
            i+=1
            j+=1
        elif st and st[-1]==b[j]:
            st.pop()
            j+=1
        elif i<n:
            st.append(a[i])
            i+=1
        else:
            flag=False
            break
    if flag:
        print("Yes")
    else:
        print("No")
    m-=1
"""
2
5
1 2 3 4 5
5 4 3 2 1
4
1 2 3 4
2 4 1 3
"""