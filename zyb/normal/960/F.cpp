#include<bits/stdc++.h>
#define N 100005
using namespace std;
int i,j,k,l,s,n,m,tot,st[N];
struct node {
	int v,ls,rs;
}f[10000005];
int ans,x,y,z;
inline void change(int o,int l,int r,int ll,int p) {
	f[o].v=max(f[o].v,p);
	if (l==ll&&r==ll) return ;
	int mid=(l+r)>>1;
	if (ll<=mid) {
		if (!f[o].ls) f[o].ls=++tot;
		change(f[o].ls,l,mid,ll,p);
	}
	else {
		if (!f[o].rs) f[o].rs=++tot;
		change(f[o].rs,mid+1,r,ll,p);
	}
}
inline int ask(int o,int l,int r,int ll,int rr) {
	if (ll>rr) return 0;
	if (!o) return 0;
	if (l==ll&&r==rr) return f[o].v;
	int mid=(l+r)>>1;
	if (rr<=mid) return ask(f[o].ls,l,mid,ll,rr);
	else if (ll>mid) return ask(f[o].rs,mid+1,r,ll,rr);
	else return max(ask(f[o].ls,l,mid,ll,mid),ask(f[o].rs,mid+1,r,mid+1,rr));
}
int main() {
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) st[i]=++tot;
	for (i=1;i<=m;i++) {
		scanf("%d%d%d",&x,&y,&z);
		int gt=ask(st[x],0,100000,0,z-1);
		change(st[y],0,100000,z,gt+1);
		ans=max(ans,gt+1);
	}
	printf("%d\n",ans);
}