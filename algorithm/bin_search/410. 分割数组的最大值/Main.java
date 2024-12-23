package com.example;
import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int [] a = new int [n];
        for(int i=0;i<n;i++){
            a[i] = scanner.nextInt();
        }
        int k = scanner.nextInt();
        System.out.println(splitArray(a, k));
    }
    static int splitArray(int[] a, int k) {
        //初始化l,r ;
        int l=a[0], r = 0;
        for(int i=0;i<a.length;i++){
            l = Math.max(l, a[i]);
            r+=a[i];
        }
        while(l<r){
            int mid = l+(r-l)/2;
            if(f(a, k, mid)){
                r=mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;

    }
    static boolean f(int []a, int k, int sum){//判断是否满足k份
        int tmp = 0;
        int cnt = 0;
        for(int i=0;i<a.length;i++){
            if(tmp+a[i]>sum){//要分隔
                cnt++;
                tmp=0;
            }
            tmp+=a[i];
        }//处理最后一份
        if(tmp>0)cnt++;
        return cnt <= k;
    }
}
/*
5
7 2 5 10 8
2

3
1 4 4
3

5
1 2 3 4 5
2

 */

