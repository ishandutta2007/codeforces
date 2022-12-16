#include<bits/stdc++.h>
using namespace std;
#define N 100005
int i,j,n,m,a[N],k;
double ans;
int main() {
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	k=1;
	int bb=0;
	for (i=1;i<n;i++) {
		j=i+1;
		while (a[k]-a[i]<=m&&k<=n) k++;
		if (k<=j+1) continue;
		bb=1;
		ans=max(ans,1.*(a[k-1]-a[j])/(a[k-1]-a[i]));
	}
	if (!bb) puts("-1");
	else printf("%.10lf\n",ans);
}