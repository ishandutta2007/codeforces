#include<bits/stdc++.h>
using namespace std;
#define N 500005
#define ls (o<<1)
#define rs ((o<<1)+1)
struct tree {
	int id;
	long long d,mi;
}f[N*4];
struct node {
	int x,y,z;
}b[N];
int q[N],n,tot,r;
map<int,int>ma;
vector<int>A[N],a;
#define pb push_back
set<int>G;
set<int>::iterator gt;
long long F[N];
#define lowbit(x) x&-x
#define inf 1000000000000000000ll
inline void change(int x,long long y) {
	for (;x<=r;x+=lowbit(x)) F[x]+=y;
}
inline long long ask(int x) {
	long long s=0;
	for (;x;x-=lowbit(x)) s+=F[x];
	return s;
}
inline bool cmp(int x,int y) {
	return b[x].y<b[y].y;
}
inline void build(int o,int l,int r) {
	f[o].mi=inf;
	if (l==r) {
		f[o].id=q[l];
		return ;	
	}
	int mid=(l+r)>>1;
	build(ls,l,mid),build(rs,mid+1,r);
}
inline void down(int o) {
	if (!f[o].d) return ;
	f[ls].mi+=f[o].d;
	f[ls].d+=f[o].d;
	f[rs].mi+=f[o].d;
	f[rs].d+=f[o].d;
	f[o].d=0;
}
inline void change(int o,int l,int r,int ll,long long p) {
	if (l==ll&&r==ll) {
		f[o].mi=p;
		return ;
	}
	down(o);
	int mid=(l+r)>>1;
	if (ll<=mid) change(ls,l,mid,ll,p);
	else change(rs,mid+1,r,ll,p);
	f[o].mi=min(f[ls].mi,f[rs].mi);
}
inline void change(int o,int l,int r,int ll,int rr,int p) {
	if (ll>rr) return ;
	if (l==ll&&r==rr) {
		f[o].mi+=p;
		f[o].d+=p;
		return ;
	}
	down(o);
	int mid=(l+r)>>1;
	if (rr<=mid) change(ls,l,mid,ll,rr,p);
	else if (ll>mid) change(rs,mid+1,r,ll,rr,p);
	else change(ls,l,mid,ll,mid,p),change(rs,mid+1,r,mid+1,rr,p);
	f[o].mi=min(f[ls].mi,f[rs].mi);
}
inline void ask(int o,int l,int r) {
	if (l==r) {
		if (f[o].mi<0) G.insert(f[o].id),f[o].mi=inf;
		return ;
	}
	down(o);
	int mid=(l+r)>>1;
	if (f[ls].mi<0) ask(ls,l,mid);
	if (f[rs].mi<0) ask(rs,mid+1,r);
	f[o].mi=min(f[ls].mi,f[rs].mi);
}
int main() {
	scanf("%d",&n);
	int ans=0;
	for (int i=1;i<=n;i++) {
		char c=getchar();
		while (c!='+'&&c!='-') c=getchar();
		if (c=='+') b[i].x=1;
		else b[i].x=0;
		scanf("%d",&b[i].y);
		if (b[i].x==1) q[++r]=i;
	}
	sort(q+1,q+1+r,cmp);
	for (int i=1;i<=r;i++) b[q[i]].z=i;
	build(1,1,r);
	for (int i=1;i<=n;i++) {
		if (!ma[b[i].y]) ma[b[i].y]=++tot;
		int Y=ma[b[i].y];
		if (b[i].x==1) {
			A[Y].pb(i);
			ans++;
			long long sum=ask(b[i].z);
			long long p=(b[i].y+1)/2;
			change(b[i].z,b[i].y);
			if (sum>=p) {
				change(1,1,r,b[i].z,sum-p);
				change(1,1,r,b[i].z+1,r,b[i].y);
			} 
			else {
				change(1,1,r,b[i].z+1,r,b[i].y);
				G.insert(i);
			}
			a.clear();
			for (gt=G.begin();gt!=G.end();gt++) {
				int tmp=*gt;
				if (b[tmp].z<=b[i].z) continue;
				sum=ask(b[tmp].z-1);
				p=(b[tmp].y+1)>>1;
				if (sum>=p) {
					a.pb(tmp);
					change(1,1,r,b[tmp].z,sum-p);
				}
			}
			for (int i=0;i<a.size();i++) G.erase(a[i]);
			printf("%d\n",ans-(int)G.size());
		}
		else {
			int x=*A[Y].begin();
			change(b[x].z,-b[x].y);
			A[Y].erase(A[Y].begin());
			change(1,1,r,b[x].z+1,r,-b[x].y);
			change(1,1,r,b[x].z,inf);
			ask(1,1,r);
			gt=G.find(x);
			if (gt!=G.end()) G.erase(gt);
			ans--;
			printf("%d\n",ans-(int)G.size());
		}
	}
}