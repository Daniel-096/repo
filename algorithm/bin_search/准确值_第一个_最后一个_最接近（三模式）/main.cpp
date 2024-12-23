#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int find(int a[], int l, int r, int tar){
		while(l<=r){
			int mid= l+(r-l)/2;
			if(a[mid]>tar){
				r = mid-1;
			}
			else if (a[mid]<tar){
				l = mid+1;
			}
			else{
				return mid;
			}
		}
		return -1;
	}
	int find_first(int a[], int l, int r, int tar){
		while(l<r){
			int mid= l+(r-l)/2;
			if(a[mid]>tar){
				r = mid-1;
			}
			else if (a[mid]<tar){
				l = mid+1;
			}
			else {
				r=mid;
			}
		}
		return l;
	}
	int find_last(int a[], int l, int r, int tar){
		while(l<r){
			int mid= l+(r-l+1)/2;
			if(a[mid]>tar){
				r = mid-1;
			}
			else if (a[mid]<tar){
				l = mid+1;
			}
			else{
				l=mid;
			}
		}
		return l;
	}
	int find_close(int a[], int l, int r, int tar){
		while(l<r-1){
			int mid= l+(r-l)/2;
			if(a[mid]>tar){
				r = mid;
			}
			else if (a[mid]<tar){
				l = mid;
			}
			else{
				return mid;
			}
		}
		if(a[l]>tar){
			return l;
		}
		else if (tar>a[r]){
			return r;
		}
		else return a[r] - tar>tar-a[l] ? l:r;
	}

};
int main(){
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    printf("%d\n",Solution().find(a,0, n-1, 6));
	printf("%d\n",Solution().find_first(a, 0, n-1, 2));
	printf("%d\n",Solution().find_last(a,0, n-1, 2));
	printf("%d\n",Solution().find_close(a,0, n-1, 5));
}
/*
7
1 1 2 2 2 6 7
*/
