package com.example;

import java.util.*;
class Main{
    public static void main(String[] args) {
        TreeSet<Integer>s = new TreeSet<>();
        Scanner sc = new Scanner(System.in);
        s.add(-0x7fffffff);
        s.add(Integer.MAX_VALUE);
        int n = sc.nextInt();
        while(n-->0){
            int op = sc.nextInt(), num = sc.nextInt();
            if(op==1){//位数
                int cur = s.lower(num);//不含自己
                int cnt=1;
                for(Integer p:s){
                    if(p==cur){
                        break;
                    }
                    cnt++;
                }
                System.out.println(cnt);
            } else if (op==2) {//第x个数
                int cnt=0;
                for(Integer p:s){
                    if(cnt==num){
                        System.out.println(p);
                        break;
                    }
                    cnt++;
                }


            } else if (op==3) {//前驱
                System.out.println(s.lower(num));
            } else if (op==4) {
                System.out.println(s.higher(num));
            }
            else {
                s.add(num);
            }
        }

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