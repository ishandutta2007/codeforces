#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAX_N = 8;

int a[MAX_N];
int ans[MAX_N];

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		for (int i=0;n>i;i++) {
			a[i] = i+1;
		}
		int mx = -1;
		int cnt=0;
		do {
			int val=0;
			for (int i=0;n>i;i++) {
				for (int j=i;n>j;j++) {
					int mn = n+1;
					for (int k=i;j>=k;k++) {
						mn = min(mn,a[k]);
					}
					val += mn;
				}
			}
			if (val > mx) {
				mx = val;
				cnt=1;
				if (m==1) {
					for (int i=0;n>i;i++) ans[i]=a[i];
				}
			}
			else if (val == mx ){
				cnt++;
				if (cnt == m) {
					for (int i=0;n>i;i++) ans[i]=a[i];
				}
			}
		} while(next_permutation(a,a+n));
		for (int i=0;n>i;i++) {
			if (i) printf(" ");
			printf("%d",ans[i]);
		}
		puts("");
	}
}