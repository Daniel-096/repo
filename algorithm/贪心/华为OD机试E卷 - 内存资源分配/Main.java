package com.example;
import java.util.*;
class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String [] s = sc.next().split(",");
        TreeMap<Integer, Integer>mp = new TreeMap<>();
        for(int i=0;i<s.length;i++){
            String []tmp = s[i].split(":");
            int size = Integer.parseInt(tmp[0]), num = Integer.parseInt(tmp[1]);
            mp.put(size,mp.getOrDefault(size,0)+num);
        }
        s = sc.next().split(",");
        for(int i=0;i<s.length;i++){
            Integer tmp = mp.ceilingKey(Integer.parseInt(s[i]));
            if(tmp!=null){
                int val = mp.get(tmp);
                if(val>1){
                    mp.put(tmp,val-1);
                }
                else{
                    mp.remove(tmp);
                }
                System.out.print("true");
            }
            else {
                System.out.print("false");
            }
            if(i<s.length-1) System.out.print(",");
        }
        System.out.println();
    }
}
/*
64:2,128:1,32:4,1:128
50,36,64,128,127

 */