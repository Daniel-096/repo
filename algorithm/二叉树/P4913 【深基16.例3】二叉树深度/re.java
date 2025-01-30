package com.example;

import java.util.*;
class Main{
    static int maxH = 0;
    static Node []a;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        a = new Node[(int)1e6+5];
        for(int i=1;i<=n;i++){
            int l = sc.nextInt();
            int r = sc.nextInt();
            a[i] = new Node(l,r);
        }
        dfs(a[1],1);
        System.out.println(maxH);
    }
    static void dfs(Node cur, int h){
        maxH = Math.max(maxH,h);
        if(cur.l!=0)dfs(a[cur.l],h+1);
        if(cur.r!=0)dfs(a[cur.r],h+1);
    }
    static class Node{
        int l;
        int r;
        public Node(int l, int r) {
            this.l = l;
            this.r = r;
        }
    }
}
/*
7
2 7
3 6
4 5
0 0
0 0
0 0
0 0
 */