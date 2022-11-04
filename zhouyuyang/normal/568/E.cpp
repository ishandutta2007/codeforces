#include<bits/stdc++.h>
using namespace std;

#define pa pair<int,int>
const int M=5e6+5;
pa t[M];
int ls[M],rs[M];
int sz,rt;
void clear(){
	for (;sz;sz--){
		ls[sz]=rs[sz]=0;
		t[sz]=t[0];
	}
	sz=rt=0;
}
void insert(int &k,int l,int r,int p,pa v){
	if (!k) k=++sz;
	t[k]=max(t[k],v);
	if (l==r) return;
	int mid=l+(r-l+1+1)/2-1;
	if (p<=mid) insert(ls[k],l,mid,p,v);
	else insert(rs[k],mid+1,r,p,v);
}
pa ask(int k,int l,int r,int x,int y){
	if (!k||(l==x&&r==y)) return t[k];
	int mid=l+(r-l+1+1)/2-1;
	if (y<=mid) return ask(ls[k],l,mid,x,y);
	if (x>mid) return ask(rs[k],mid+1,r,x,y);
	return max(ask(ls[k],l,mid,x,mid),ask(rs[k],mid+1,r,mid+1,y));
}
#define fi first
#define se second
const int N=1e5+5;
const int lim=1e5+5;
int q[N],a[N],b[N];
int cnt[N],v1[N],v2[N];
multiset<int> s;
pa f[N];
int n,m;
bool cmp(int x,int y){
	if (a[x]!=a[y])
		return a[x]<a[y];
	return x>y;
}
//v2=lessx
//v1=nogreaterx
void work(int l,int r){
	int top=0;
	for (int i=l;i<=r;i++)
		q[++top]=i;
	sort(q+1,q+top+1,cmp);
	int mid=(l+r)/2;
	//min=cntx-cnty,cntx-lessx<=cnty-nogreatery
	for (int i=1;i<=top;i++){
		int x=q[i];
		if (q[i]<=mid)
			insert(rt,-lim,lim,cnt[x]-v1[x],pa(f[x].fi-cnt[x],x));
		else{
			pa tmp=ask(rt,-lim,lim,cnt[x]-v2[x],lim);
			tmp.fi+=cnt[x]; f[x]=max(f[x],tmp);
		}
	}
	clear();
	//min=lessx-nogreatery,cntx-lessx>=cnty-nogreatery
	for (int i=1;i<=top;i++){
		int x=q[i];
		if (q[i]<=mid)
			insert(rt,-lim,lim,cnt[x]-v1[x],pa(f[x].fi-v1[x],x));
		else{
			pa tmp=ask(rt,-lim,lim,-lim,cnt[x]-v2[x]);
			tmp.fi+=v2[x]; f[x]=max(f[x],tmp);
		}
	}
	clear();
}
void CDQ(int l,int r){
	if (l==r){
		if (a[l]!=-1)
			f[l].fi+=1;
		else f[l].fi=-1e9;
		return;
	}
	int mid=(l+r)/2;
	CDQ(l,mid);
	work(l,r);
	CDQ(mid+1,r);
}
int main(){
	t[0]=pa(-2e9,-2e9);
	for (int i=1;i<M;i++) t[i]=t[0];
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	a[0]=-2e9; a[n+1]=2e9;
	for (int i=1;i<=n+1;i++)
		cnt[i]=cnt[i-1]+(a[i]==-1);
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
		scanf("%d",&b[i]),s.insert(b[i]);
	sort(b+1,b+m+1); b[0]=-2147480000;
	m=unique(b+1,b+m+1)-b-1;
	for (int i=0;i<=n+1;i++){
		v1[i]=upper_bound(b+1,b+m+1,a[i])-b-1;
		v2[i]=v1[i]-(b[v1[i]]==a[i]);
	}
	CDQ(0,n+1);
	for (int x=n+1;x;x=f[x].se){
		int vl=v1[f[x].se]+1,vr=v2[x];
		//printf("%d %d %d %d\n",x,f[x].se,vl,vr);
		for (int i=f[x].se+1;i<=x;i++)
			if (a[i]==-1&&vl<=vr){
				a[i]=b[vl]; s.erase(s.find(b[vl])); vl++;
			}
	}
	int top=1;
	for (int i=1;i<=n;i++)
		if (a[i]==-1){
			a[i]=*s.begin();
			s.erase(s.begin());
		}
	for (int i=1;i<=n;i++)
		printf("%d ",a[i]);
}
/*
f[x]=max(f[y]+min(cntx-cnty,lessx-nogreatery))+1;
*/