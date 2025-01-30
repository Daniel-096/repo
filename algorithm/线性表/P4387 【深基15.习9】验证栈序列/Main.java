package com.example;
//import org.w3c.dom.Node;

//import org.w3c.dom.Node;

import java.util.*;
class Main{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        final int maxN = (int)1e5+5;
        int []a = new int[maxN];
        int []b = new int[maxN];
        while(m-->0){
            int n = scanner.nextInt();
            for(int i=0;i<n;i++){
                a[i] = scanner.nextInt();
            }
            for(int i=0;i<n;i++){
                b[i] = scanner.nextInt();
            }
            LinkedList<Integer> st = new LinkedList<>();
            int i=0,j=0;
            boolean flag = true;
            while(j<n){
                if(a[i]==b[j]){
                    i++;
                    j++;
                }
                else if(!st.isEmpty()&&st.getLast()==b[j]){
                    st.removeLast();
                    j++;
                }
                else if(i<n){
                    st.add(a[i++]);
                }
                else{
                    flag=false;
                    break;
                }
            }
            if(flag) System.out.println("Yes");
            else System.out.println("No");
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
/*
2
5
1 2 3 4 5
5 4 3 2 1
4
1 2 3 4
2 4 1 3
 */