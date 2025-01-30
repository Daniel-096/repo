package com.example;
//import org.w3c.dom.Node;

//import org.w3c.dom.Node;

import java.util.*;
class Main{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        boolean []vis =new boolean[105];
        Arrays.fill(vis, false);
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)==')'){
                for(int j=i-1;j>=0;j--){
                    if(s.charAt(j)=='['&&!vis[j]){
                        break;
                    } else if (s.charAt(j)=='('&&!vis[j]) {
                        vis[j]=true;
                        vis[i]=true;
                        break;
                    }
                }
            }
            else if(s.charAt(i)==']'){
                for(int j=i-1;j>=0;j--){
                    if(s.charAt(j)=='('&&!vis[j]){
                        break;
                    } else if (s.charAt(j)=='['&&!vis[j]) {
                        vis[j]=true;
                        vis[i]=true;
                        break;
                    }
                }
            }
        }
        for(int i=0;i<s.length();i++){
            if(!vis[i]){
                if(s.charAt(i)==')'||s.charAt(i)=='('){
                    System.out.print("()");
                }
                else{
                    System.out.print("[]");
                }
            }
            else System.out.print(s.charAt(i));
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
([)])
 */