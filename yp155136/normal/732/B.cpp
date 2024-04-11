#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 506;

int a[MAX_N];
int b[MAX_N];

int main () {
	int n,k;
	while (scanf("%d %d",&n,&k) != EOF) {
		for (int x=1;n>=x;x++) {
			scanf("%d",&a[x]);
			b[x] = a[x];
		}
		if (n==1) {
			int x=n;
			printf("0\n%d\n",a[x]);
			continue;
		}
		//start at day 1
		int ans=0;
		for (int x=2;n>=x;x++) {
			if (a[x] + a[x-1] < k) {
				ans += (k-a[x]-a[x-1]);
				a[x] += (k-a[x]-a[x-1]);
			}
		}
		int ans1=0;
		for (int x=n-1;x>=0;x--) {
			if (b[x] + b[x+1] < k) {
				ans1 += (k-b[x]-b[x+1]);
				b[x] += (k-b[x]-b[x+1]);
			}
		}
		if (ans <= ans1) {
			printf("%d\n",ans);
			for (int x=1;n>=x;x++) {
				if (x!=1) printf(" ");
				printf("%d",a[x]);
			}
			puts("");
		}
		else {
			printf("%d\n",ans1);
			for (int x=1;n>=x;x++) {
				if (x!=1) printf(" ");
				printf("%d",b[x]);
			}
			puts("");
		}
	}
}