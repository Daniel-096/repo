class Node:
    def __init__(self, l=0, r=0):
        self.l = l  # 左子节点索引
        self.r = r  # 右子节点索引

def dfs(tree, cur_index, h):
    global maxH
    # print("cur:{}".format(cur_index))
    maxH = max(h, maxH)
    if tree[cur_index].l != 0:
        dfs(tree, tree[cur_index].l, h + 1)  # 递归遍历左子树
    if tree[cur_index].r != 0:
        dfs(tree, tree[cur_index].r, h + 1)  # 递归遍历右子树

if __name__ == "__main__":
    n = int(input())  # 读取节点数
    tree = [Node() for _ in range(n + 2)]  # 初始化树（数组模拟二叉树）

    for i in range(1, n + 1):
        l, r = map(int, input().split())
        tree[i].l = l
        tree[i].r = r

    maxH = 0  # 全局变量记录最大高度
    dfs(tree, 1, 1)  # 从根节点开始 DFS，初始高度为 1
    print(maxH)

"""
1
0 0
"""