#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <utility>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
const int MAX_N = 2e5 + 6;

int a[MAX_N],b[MAX_N];

struct _ {
	int c,d,e;
	void __(int id) {
		c=a[id];
		d=b[id];
		e=max(0,a[id]-b[id]);
	}
} ___[MAX_N];

bool operator<(const _ &p1,const _ &p2) {
	return p1.e < p2.e;
}

int main () {
	int n,k;
	while (scanf("%d %d",&n,&k) != EOF) {
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i]);
		}
		for (int i=1;n>=i;i++) {
			scanf("%d",&b[i]);
		}
		LL ans=0;
		for (int i=1;n>=i;i++) {
			___[i].__(i);
		}
		sort(___+1,___+n+1);
		for (int i=1;k>=i;i++) {
			ans += ___[i].c;
		}
		for (int i=k+1;n>=i;i++) {
			ans += min(___[i].c,___[i].d);
		}
		printf("%I64d\n",ans);
	}
}