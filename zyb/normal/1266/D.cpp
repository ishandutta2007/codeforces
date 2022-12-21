#include<bits/stdc++.h>
#define N 1000005
using namespace std;
struct pa {
	int x,y;
	long long v;
}da[N];
int n,m,tot,A[N],B[N],s1,s2;
long long a[N],b[N];
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) {
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		a[x]+=z;
		b[y]+=z;
	}
	for (int i=1;i<=n;i++) {
		long long p=min(a[i],b[i]);
		a[i]-=p;
		b[i]-=p;
		if (a[i]>0) A[++s1]=i;
		if (b[i]>0) B[++s2]=i;
	}
	int j=1;
	for (int i=1;i<=s1;) {
		if (a[A[i]]>b[B[j]]) {
			long long p=b[B[j]];
			da[++tot]=pa{A[i],B[j],p};
			a[A[i]]-=p;
			j++;
		}
		else {
			long long p=a[A[i]];
			da[++tot]=pa{A[i],B[j],p};
			a[A[i]]-=p;
			b[B[j]]-=p;
			i++;
			if (!b[B[j]]) j++;
		}
	}
	printf("%d\n",tot);
	for (int i=1;i<=tot;i++) printf("%d %d %lld\n",da[i].x,da[i].y,da[i].v);
}