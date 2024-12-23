package com.example;



import java.util.*;
class Node implements Comparable<Node>{
    public int start;
    public int end;

    public Node(int start, int end) {
        this.start = start;
        this.end = end;
    }

    @Override
    public int compareTo(Node o) {
        return this.start - o.start;
    }
}

class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int [] a = new int[n];
        for(int i=0;i<n;i++){
            a[i] = scanner.nextInt();
        }
        System.out.println("第一个2:"+bin_search_first(a, 0, n-1, 2));
        System.out.println("最后一个2:"+bin_search_last(a, 0, n-1, 2));
        System.out.println("6的位置:"+bin_search_one(a, 0, n-1, 6));
        System.out.println("10的位置:"+bin_search_one(a, 0, n-1, 10));
        System.out.println("最接近5的位置:"+bin_search_close(a, 0, n-1, 5));

    }
    //模糊值
    static int bin_search_first(int []a, int l, int r, int tar){//找第一个tar的位置
        while(l<r){
            int mid = l + (r-l)/2;
            if(a[mid]>tar){
                r = mid-1;
            }
            else if(a[mid]<tar){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        return l;
    }

    static int bin_search_last(int []a, int l, int r, int tar){//找第一个tar的位置
        while(l<r){
            int mid = l + (r-l+1)/2;//让偶数个数落在右边
            if(a[mid]>tar){
                r = mid-1;
            }
            else if(a[mid]<tar){
                l = mid+1;
            }
            else{
                l = mid;
            }
        }
        return l;
    }
    //准确值
    static int bin_search_one(int []a, int l, int r, int tar) {//准确位置
        while(l<=r){
            int mid = l+(r-l)/2;
            if(a[mid]>tar){
                r = mid-1;
            }
            else if(a[mid]<tar){
                l = mid+1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
    //万用型
    static int bin_search_close(int []a, int l, int r, int tar) {//最接近tar
        while(l<r-1){
            int mid = l+(r-l)/2;
            if(a[mid]>tar){
                r = mid;
            }
            else if(a[mid]<tar){
                l = mid;
            }
            else{
                return mid;
            }
        }
        if(a[r]<tar) {
            return r;
        }
        else if(a[l]>tar){
            return l;
        }
        else return tar - a[l]>a[r]-tar ? r:l;
    }
}
/*
7
1 1 2 2 2 6 7

 */

