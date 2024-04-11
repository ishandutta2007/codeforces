#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
using namespace std;

const int MAX_N = 1e6 + 6;

int prime[MAX_N];
int cnt[MAX_N];
int c[MAX_N];

void init() {
	memset(prime,-1,sizeof(prime));
	for (int x=2;MAX_N>x;x++) {
		if (prime[x]==-1) {
			for (int i=x;MAX_N>i;i+=x) {
				prime[i]=x;
			}
		}
	}
}

int main () {
	init();
	int n,k;
	while (scanf("%d %d",&n,&k) !=EOF) {
		memset(cnt,0,sizeof(cnt));
		for (int x=1;n>=x;x++) {
			scanf("%d",&c[x]);
			int tmp=c[x];
			while (tmp>1) {
				int p=prime[tmp];
				int i=0;
				while (tmp%p==0) {
					tmp/=p;
					i++;
				}
				cnt[p] = max(cnt[p],i);
			}
		}
		bool check=false;
		while (k>1) {
			int p=prime[k];
			int i=0;
			while (k%p==0) {
				k/=p;
				i++;
			}
			if (cnt[p] < i) check=true;
		}
		if (check) puts("No");
		else puts("Yes");
	}
}