package com.example;
import java.util.*;
class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), k = sc.nextInt(), x = sc.nextInt();
        Node []nodes = new Node[n];
        for(int i=0;i<n;i++){
            nodes[i] = new Node(sc.nextInt());
//            nodes[i].val = ;
            nodes[i].tar = x;
        }
        Arrays.sort(nodes, new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                if(Math.abs(o1.tar-o1.val)==Math.abs(o2.tar-o2.val)){
                    return o1.val - o2.val;
                }
                return Math.abs(o1.tar-o1.val) - Math.abs(o2.tar-o2.val);
            }
        });
        Arrays.sort(nodes, 0, k, new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return o1.val - o2.val;
            }
        });
        for(int i=0;i<k;i++){
            System.out.print(nodes[i].val);
            if(i<k-1) System.out.print(" ");
        }
        System.out.println();
    }
    static class Node{
        int val;
        int tar;

        public Node(int val) {
            this.val = val;
        }
    }
}
/*
10 5 6
1 2 3 4 5 6 7 8 9 10

 */