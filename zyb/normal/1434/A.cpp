#include<bits/stdc++.h>
using namespace std;
#define N 100005
struct pa {
	int v,x;
}q[N*10];
int A[N][10],d[N],a[N],b[N],n;
inline bool cmp(pa x,pa y) {
	if (x.v!=y.v)
	return x.v<y.v;
	return x.x<y.x;
}
int main() {
	for (int i=1;i<=6;i++) scanf("%d",&b[i]);
	scanf("%d",&n);
	int r=0,s=-1000000000;
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		for (int j=1;j<=6;j++) A[i][j]=a[i]-b[j],q[++r]=pa{a[i]-b[j],i};
		sort(A[i]+1,A[i]+1+6);
		d[i]=1;
		s=max(s,A[i][1]);
	}
	int ans=1000000000;
	sort(q+1,q+1+r,cmp);
	for (int i=1;i<=r;i++) {
		ans=min(ans,s-q[i].v);
		d[q[i].x]++;
		if (d[q[i].x]>6) break;
		s=max(s,A[q[i].x][d[q[i].x]]);
	}
	printf("%d\n",ans);
}