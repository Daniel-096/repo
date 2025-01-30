package com.example;
import java.util.*;
class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] s = sc.next().split(";");//按下标访问和删除
        ArrayList<Node>a = new ArrayList<>();
        HashMap<String, Integer>mp = new HashMap<>();
        for(int i=0;i<s.length;i++){
            String []tmp = s[i].split(",");
//            System.out.println();
            mp.put(tmp[0],i);
            Node cur = new Node(Integer.parseInt(tmp[1])-1000, tmp[0]);
            a.add(cur);
        }
        s = sc.next().split(";");
        for(String str:s){
            String []tmp = str.split(",");
            if(mp.containsKey(tmp[0])){
                int j = mp.get(tmp[0]);
                Node cur = a.get(j);
                cur.val += 1000+Integer.parseInt(tmp[1]);
                a.set(j, cur);
            }
        }
        int j = 0;
        while(j<a.size()){
            if(a.get(j).val<0){
                a.remove(j);
            }
            else{
                j++;
            }
        }
        a.sort(new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                if(o1.classNum.substring(0,5).compareTo(o2.classNum.substring(0,5))==0){
                    if(o1.val==o2.val){
                        return o1.classNum.substring(5,8).compareTo(o2.classNum.substring(5,8));
                    }
                    return o2.val - o1.val;
                }
                return o1.classNum.substring(0,5).compareTo(o2.classNum.substring(0,5));
            }
        });//排序
        if(a.size()==0){
            System.out.println("NULL");
            return;
        }
        String pre = a.get(0).classNum.substring(0, 5);
        StringBuilder str = new StringBuilder();
        str.append(pre).append("\n");
        for(int i=0;i<a.size();i++){
            if(pre.compareTo(a.get(i).classNum.substring(0, 5))!=0){
                pre = a.get(i).classNum.substring(0, 5);
                str.delete(str.length()-1, str.length());//删 ;
                str.append("\n"+pre+"\n");
            }
            str.append(a.get(i).classNum+";");
        }
        str.delete(str.length()-1, str.length());//删 ;
        System.out.println(str.toString());



    }
    static class Node{
        int val;
        String classNum;

        public Node(int val, String classNum) {
            this.val = val;
            this.classNum = classNum;
        }
    }
}
/*
01202021,75;01201033,95;01202008,80;01203006,90;01203088,100
01202008,70;01203088,85;01202111,80;01202021,75;01201100,88



01201022,75;01202033,95;01202018,80;01203006,90;01202066,100
01202008,70;01203102,85;01202111,80;01201021,75;01201100,88


01202
01202008;01202021
01203
01203088
 */