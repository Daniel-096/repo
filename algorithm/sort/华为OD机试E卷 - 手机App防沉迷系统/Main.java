package com.example;
import java.util.*;
class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Node [] nodes = new Node[n];
        for(int i=0;i<n;i++){
            nodes[i] = new Node(sc.next(),sc.nextInt());
            nodes[i].beginTime = getTime(sc.next());
            nodes[i].endTime = getTime(sc.next());
        }
        int []tar = getTime(sc.next());
        Node ans = new Node("NA",-1);
        for(int i=0;i<n;i++){
            if(timeVal(nodes[i].beginTime)<timeVal(nodes[i].endTime) &&
                    timeVal(nodes[i].beginTime)<=timeVal(tar) &&
            timeVal(nodes[i].endTime)>timeVal(tar)){
                if(ans.name.compareTo("NA")==0||!change(ans,nodes[i])){
                    ans = nodes[i];
                }
            }
        }
        System.out.println(ans.name);
    }
    static boolean change(Node o1, Node o2){
        if(o1.level==o2.level){
            return timeVal(o1.beginTime)<timeVal(o2.beginTime);
        }
        return o1.level>o2.level;
    }
    static int timeVal(int []a){
        return a[0]*60+a[1];
    }
    static int[] getTime(String s){
        int []a = new int[2];
        a[0] = Integer.parseInt(s.substring(0,2));
        a[1] = Integer.parseInt(s.substring(3,5));
        return a;
    }
    static class Node{
        String name;
        int level;
        int []beginTime;
        int []endTime;

        public Node(String name, int level) {
            this.name = name;
            this.level = level;
        }
    }
}
/*
2
App1 1 09:00 10:00
App2 2 09:10 09:30
09:20

 */