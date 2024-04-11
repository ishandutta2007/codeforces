#include<bits/stdc++.h>
using namespace std;
const int N=200005;
#define ull unsigned long long
struct node{
	ull mx:18,l:23,r:23;
}t[N*40];
int sz;
#define L(x) t[x].l
#define R(x) t[x].r
#define MX(x) t[x].mx
#define UPD(x) max(int(mid>l?MX(L(x)):L(x)),int(r>mid+1?MX(R(x)):R(x)))
#define TAG(x) (MX(x)-UPD(x))
int upd(int k,int l,int r,int x,int y){
	if (l==r) return k+1;
	int nk=++sz; t[nk]=t[k];
	if (l==x&&r==y) return MX(nk)++,nk;
	int mid=(l+r)/2,tg=TAG(k);
	if (y<=mid) L(nk)=upd(L(k),l,mid,x,y);
	else if (x>mid) R(nk)=upd(R(k),mid+1,r,x,y);
	else L(nk)=upd(L(k),l,mid,x,mid),
		 R(nk)=upd(R(k),mid+1,r,mid+1,y);
	MX(nk)=UPD(nk)+tg; return nk;
}
int ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return r>l?MX(k):k;
	int mid=(l+r)/2,tg=TAG(k);
	if (y<=mid) return ask(L(k),l,mid,x,y)+tg;
	if (x>mid) return ask(R(k),mid+1,r,x,y)+tg;
	int v1=ask(L(k),l,mid,x,mid);
	int v2=ask(R(k),mid+1,r,mid+1,y);
	return max(v1,v2)+tg;
}
int n,m,q,rt[N];
#define pa pair<int,int>
#define fi first
#define se second
pa v[N];
void init(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&v[i].fi);
		v[i].fi*=-1; v[i].se=i;
	}
	sort(v+1,v+n+1);
	for (int i=1;i<=n;i++){
		int l=max(1,v[i].se-m+1);
		int r=min(n-m+1,v[i].se);
		rt[i]=upd(rt[i-1],1,n-m+1,l,r);
	}
}
int ans;
void solve(){
	scanf("%d",&q);
	while (q--){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k); k^=ans;
		k=upper_bound(v+1,v+n+1,pa(-k,1e9))-v-1;
		ans=m-ask(rt[k],1,n-m+1,l,r);
		printf("%d\n",ans);
	}
}
int main(){
	init();
	solve();
}