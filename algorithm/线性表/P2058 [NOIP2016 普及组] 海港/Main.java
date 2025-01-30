package com.example;
//import org.w3c.dom.Node;

import org.w3c.dom.Node;

import java.util.*;
class Main{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        LinkedList<Node>q = new LinkedList<>();
        Set<Integer>s = new HashSet<>();
        int []a = new int[(int)1e5+5];
        int maxLen = 86400;
        while(n-- > 0){
            int t = scanner.nextInt(), m = scanner.nextInt();
            while(!q.isEmpty()&&t - q.peek().t>=maxLen) {
                Node tmp = q.poll();
                a[tmp.id] -= 1;
                if (a[tmp.id] == 0) {
                    s.remove(tmp.id);
                }
            }
            while(m-->0){
                Node tmp = new Node(scanner.nextInt(), t);
                q.add(tmp);
                if(a[tmp.id]==0){
                    s.add(tmp.id);
                }
                a[tmp.id]+=1;
            }
            System.out.println(s.size());
        }

    }
    static class Node{
        int id;
        int t;
        public Node(int id, int t) {
            this.id = id;
            this.t = t;
        }
    }
}