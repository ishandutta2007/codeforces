#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;

const int MAX_N = 1e5 + 6;

int cnt[MAX_N];   //how many time left the box
int to[MAX_N];    //to where?
int a[MAX_N];

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		for (int x=0;n>x;x++) {
			scanf("%d",&a[x]);
		}
		int unit=sqrt(n);
		for (int i=n-1;i>=0;i--) {
			if (i + a[i] >= n) {
				cnt[i]=0;
				to[i]=i;
			}
			else {
				int tmp=i+a[i];
				if (tmp/unit == i/unit) {  //in the same box
					cnt[i]=cnt[tmp]+1;
					to[i]=to[tmp];
				}
				else {
					cnt[i]=1;
					to[i]=tmp;
				}
			}
		}
		while (m--) {
			int i,j,k;
			scanf("%d %d",&i,&j);
			if (!i) scanf("%d",&k);
			j--;
			if (!i) {
				a[j]=k;
				for (int i=j;i/unit==j/unit && i>=0;i--) {
					if (i + a[i] >= n) {
						cnt[i]=0;
						to[i]=i;
					}
					else {
						int tmp=i+a[i];
						if (tmp/unit == i/unit) {  //in the same box
							cnt[i]=cnt[tmp]+1;
							to[i]=to[tmp];
						}
						else {
							cnt[i]=1;
							to[i]=tmp;
						}
					}
				}
			}
			else {
				int ans=0;
				while (to[j] != j) {
					ans += cnt[j];
					j=to[j];
				}
				printf("%d %d\n",j+1,ans+1);
			}
		}
	}
}