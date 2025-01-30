package com.example;

import java.util.*;
class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LinkedList<Node> a = new LinkedList<>();
        int n = sc.nextInt();
        n = 1<<n;
        for(int i=1;i<=n;i++){
            a.add(new Node(i, sc.nextInt()));
        }
        while(a.size()>2){
            int len = a.size()/2;
            while(len-->0){
                Node b = a.poll();
                Node c = a.poll();
                if(b.val>c.val){
                    a.add(b);
                }
                else{
                    a.add(c);
                }
            }
        }
//        System.out.println(a.getFirst().val);
        System.out.println(a.getFirst().val>a.getLast().val?a.getLast().id:a.getFirst().id);

    }
    static class Node{
        int id;
        int val;
        public Node(int id, int val) {
            this.id = id;
            this.val = val;
        }
    }
}
/*
6
5
1
2
5
4
6

 */