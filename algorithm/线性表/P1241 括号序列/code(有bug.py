s = input()
vis = [False] * 105

# print(list(reversed(range(4))))
for i in range(len(s)):
    if s[i] == ')':
        for j in range(i-1,-1,-1):
            if s[j] == '(' and not vis[j]:
                vis[j] = True
                vis[i]=True
                break
            elif s[j] == '[' and not vis[j]:
                break
    elif s[i] == ']':
        for j in range(i-1,-1,-1):
            if s[j] == '[' and not vis[j]:
                vis[j] = True
                vis[i]=True
                break
            elif s[j] == '(' and not vis[j]:
                break
for i in range(len(s)):
    if not vis[i]:
        if s[i]=='(' or s[i] ==')':
            print("()",end='')
        else:
            print("[]",end='')
    else:
        print(s[i],end='')
# print(vis)
"""
([)])
"""