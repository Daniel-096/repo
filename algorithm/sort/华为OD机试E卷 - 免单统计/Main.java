package com.example;
import java.util.*;
class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();//类似cin.ignore(),消除多余\n
        TreeMap<String, Integer>mp = new TreeMap<>();
        for(int i=0;i<n;i++){
            String tmp = sc.nextLine();
//            System.out.println(tmp);
            mp.put(tmp, mp.getOrDefault(tmp, 0)+1);
        }
        String pre = "";
        int cnt = 0;
        for(String key:mp.keySet()){
            String cur = key.substring(0,19);
            if(cur.compareTo(pre)!=0){
                cnt+=mp.get(key);
                pre = cur;
            }
        }
        System.out.println(cnt);





    }

}
/*
5
2019-01-01 00:00:00.004
2019-01-01 00:00:00.004
2019-01-01 00:00:01.006
2019-01-01 00:00:01.006
2019-01-01 00:00:01.005

 */