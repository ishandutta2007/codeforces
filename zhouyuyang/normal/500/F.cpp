#include<bits/stdc++.h>
using namespace std;
const int N=4005;
int n,m,p,q,f[N][N],g[N][N];
struct nod{
	int co,val,t,b;
	void init(){
		scanf("%d%d%d",&co,&val,&t);
		b=(t-1)/p+1; m=max(m,t);
	}
}a[N];
bool cmp(nod a,nod b){
	return a.t<b.t;
}
int main(){
	scanf("%d%d",&n,&p);
	for (int i=1;i<=n;i++) a[i].init();
	sort(a+1,a+n+1,cmp);
	for (int i=1,l=1,r=1;i<=m;i+=p){
		for (;l<=n&&a[l].t<i;l++);
		for (;r<=n&&a[r].t<i+p;r++);
		r--;
		if (l>N||l>r) continue;
		for (int j=l,la=0;j<=r;la=j++)
			for (int k=4000;k;k--)
				f[j][k]=max(f[la][k],k>=a[j].co?f[la][k-a[j].co]+a[j].val:0);
		for (int j=r,la=0;j>=l;la=j--)
			for (int k=4000;k;k--)
				g[j][k]=max(g[la][k],k>=a[j].co?g[la][k-a[j].co]+a[j].val:0);
	}
	scanf("%d",&q);
	while (q--){
		int l,r,x,y,ans=0;
		scanf("%d%d",&x,&y);
		l=lower_bound(a+1,a+n+1,(nod){0,0,x-p+1,0},cmp)-a;
		r=upper_bound(a+1,a+n+1,(nod){0,0,x,0},cmp)-a-1;
		if (l<=r){
			if (a[l].b!=a[r].b){
				for (int i=0;i<=y;i++)
					ans=max(ans,g[l][i]+f[r][y-i]);
			}
			else{
				if (a[l].b==(x-1)/p+1)
					ans=f[r][y];
				else ans=g[l][y];
			}
		}
		printf("%d\n",ans);
	}
}