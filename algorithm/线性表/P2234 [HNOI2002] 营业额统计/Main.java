package com.example;
//import org.w3c.dom.Node;

//import org.w3c.dom.Node;

import java.util.*;
class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int maxN = (int)1e8 + 5;
        TreeSet<Integer> s = new TreeSet<>();
//        s.add(maxN);
//        s.add(-maxN);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int cur = sc.nextInt();
            if (i == 0) {
                sum += cur;
                s.add(cur);
            } else {
                // 找到当前值的下界
                Integer p = s.floor(cur);//小于等于
//                System.out.printf("cur:%d p:%d", cur, p);
                if (p != null && p == cur) {

                }
                else {
                    // 找到 p 前后的两个元素
                    Integer pos = s.ceiling(cur);
                    if(p==null) {//是最小值
                        sum+= pos - cur;
                    }
                    else if (pos == null) {
                        sum+= cur - p;
                    }
                    else {
                        sum += Math.min(Math.abs(cur - p), Math.abs(pos - cur));
                    }
                    s.add(cur);
                }
            }
        }
        System.out.println(sum);

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
6
5
1
2
5
4
6

 */