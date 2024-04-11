#include<stdio.h>
#include<algorithm>
#define lowbit(o) o&(-o)
#define N 200005
#define M 10000005
using namespace std;
int i,st[N],j,k,l,s,n,m,tot,x1,y1,x2,y2;
int a[N];
long long ans;
struct node {
	int ls,rs,v;
}f[M];
inline void build(int o,int l,int r) {
	if (l==r) return ;
	int mid=(l+r)>>1;
	f[o].ls=++tot; f[o].rs=++tot;
	build(f[o].ls,l,mid),build(f[o].rs,mid+1,r);
}
inline void change(int x,int y,int l,int r,int p) {
	f[x]=f[y]; f[x].v++;
	if (l==r) return ;
	int mid=(l+r)>>1; 
	if (p<=mid) f[x].ls=++tot,change(f[x].ls,f[y].ls,l,mid,p);
	else f[x].rs=++tot,change(f[x].rs,f[y].rs,mid+1,r,p);
}
inline int ask(int x,int y,int l,int r,int ll,int rr) {
	if (ll>rr) return 0;
	if (l==ll&&r==rr) return f[y].v-f[x].v;
	int mid=(l+r)>>1;
	if (rr<=mid) return ask(f[x].ls,f[y].ls,l,mid,ll,rr);
	else if (ll>mid) return ask(f[x].rs,f[y].rs,mid+1,r,ll,rr);
	else return ask(f[x].ls,f[y].ls,l,mid,ll,mid)+ask(f[x].rs,f[y].rs,mid+1,r,mid+1,rr);
}
inline int ask(int x1,int y1,int x2,int y2) {
	return ask(st[x1-1],st[x2],1,n,y1,y2);
}
int main() {
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	st[0]=1; build(1,1,n);
	for (i=1;i<=n;i++) {
		st[i]=++tot;
		change(st[i],st[i-1],1,n,a[i]);
	}
	for (i=1;i<=m;i++) {
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int s1=ask(1,1,x1-1,y1-1);
		int s2=ask(x1,1,x2,y1-1);
		int s3=ask(x2+1,1,n,y1-1);
		int s4=ask(1,y1,x1-1,y2);
		int s5=ask(x1,y1,x2,y2);
		int s6=ask(x2+1,y1,n,y2);
		int s7=ask(1,y2+1,x1-1,n);
		int s8=ask(x1,y2+1,x2,n);
		int s9=ask(x2+1,y2+1,n,n);
		ans=0;
		ans+=1ll*s1*(s5+s6+s8+s9);
		ans+=1ll*s2*(s4+s5+s6+s7+s8+s9);
		ans+=1ll*s3*(s4+s5+s7+s8);
		ans+=1ll*s4*(s2+s3+s5+s6+s8+s9);
		ans+=1ll*s5*(s1+s2+s3+s4+s5+s6+s7+s8+s9);
		ans-=s5;
		ans+=1ll*s6*(s1+s2+s4+s5+s7+s8);
		ans+=1ll*s7*(s2+s3+s5+s6);
		ans+=1ll*s8*(s1+s2+s3+s4+s5+s6);
		ans+=1ll*s9*(s1+s2+s4+s5);
		ans/=2;
		printf("%I64d\n",ans);
	}
}