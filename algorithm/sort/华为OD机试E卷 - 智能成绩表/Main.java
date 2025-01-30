package com.example;
//import org.w3c.dom.Node;

import java.util.*;
class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m=sc.nextInt();
        Node []nodes = new Node[n];
        String []s = new String[m];
        String tar;
        String zongfen = "zongfen";
        for(int i=0;i<m;i++){
            s[i] = sc.next();
        }
        for(int i=0;i<n;i++){
            nodes[i] = new Node(sc.next());
            int sum =0;
            for(int j=0;j<m;j++){
                int tmp = sc.nextInt();
                nodes[i].mp.put(s[j],tmp);
                sum+=tmp;
            }
            nodes[i].mp.put(zongfen, sum);
        }
        tar = sc.next();
        boolean flag = false;
        for(int i=0;i<m;i++){
            if(s[i].compareTo(tar)==0){
                flag = true;
                break;
            }
        }
        if(!flag){
            tar = zongfen;
        }
        for(int i=0;i<n;i++){
            nodes[i].tar = tar;
        }
        Arrays.sort(nodes, new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                if(o1.mp.get(o1.tar)==o2.mp.get(o2.tar)){
                    return o1.name.compareTo(o2.name);
                }
                return o2.mp.get(o2.tar) - o1.mp.get(o1.tar) ;
            }
        });
        for(int i=0;i<n;i++)
        {
            System.out.print(nodes[i].name);
            if(i<n-1) System.out.print(" ");
        }
        System.out.println();

    }
    static class Node{
        String name;
        String tar;
        HashMap<String,Integer>mp = new HashMap<>();
        public Node(String name) {
            this.name = name;
//            this.tar = tar;
//            this.mp = mp;
        }
    }
}
/*
3 2
yuwen shuxue
fangfang 95 90
xiaohua 88 98
minmin 100 82
shuxue

3 2
yuwen shuxue
fangfang 95 90
xiaohua 88 98
minmin 100 82
yuwen

3 2
yuwen shuxue
fangfang 95 90
xiaohua 88 95
minmin 90 95
zongfen

3 2
yuwen shuxue
fangfang 95 90
xiaohua 88 95
minmin 90 95
zongfen1
 */