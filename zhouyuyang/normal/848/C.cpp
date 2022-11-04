#include<bits/stdc++.h>
#define ll long long
#define M 10000000
#define N 100005
using namespace std;
ll sum[M];
int ls[M],rs[M],rt[N];
int a[N],n,m,sz;
set<int> s[N];
void change(int &k,int l,int r,int x,int v){
	if (!k) k=++sz;
	sum[k]+=v;
	if (l==r) return;
	int mid=(l+r)/2;
	if (x<=mid) change(ls[k],l,mid,x,v);
	else change(rs[k],mid+1,r,x,v);
}
ll ask(int k,int l,int r,int x,int y){
	if (!k||(l==x&&r==y)) return sum[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(ls[k],l,mid,x,y);
	if (x>mid) return ask(rs[k],mid+1,r,x,y);
	return ask(ls[k],l,mid,x,mid)+ask(rs[k],mid+1,r,mid+1,y); 
}
void change(int x,int y,int v){
	for (;x<=n;x+=x&(-x))
		change(rt[x],1,n,y,v);
}
ll ask(int x,int l,int r){
	ll ans=0;
	for (;x;x-=x&(-x))
		ans+=ask(rt[x],1,n,l,r);
	return ans;
}
void work(int v,int p,int fl){
	if (fl==-1) s[v].erase(p);
	int nxt=*s[v].lower_bound(p);
	int pre=*(--s[v].lower_bound(p));
	if (nxt<=n) change(nxt,p,fl*(nxt-p));
	if (pre>=1) change(p,pre,fl*(p-pre));
	if(nxt<=n&&pre>=1) change(nxt,pre,fl*(pre-nxt));
	if (fl==1) s[v].insert(p);
}
ll ask(int x,int y){
	return ask(y,x,y)-ask(x-1,x,y);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		s[i].insert(-1e9),s[i].insert(1e9);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),work(a[i],i,1);
	for (int i=1;i<=m;i++){
		int fl,x,y; scanf("%d%d%d",&fl,&x,&y);
		if (fl==2) printf("%I64d\n",ask(x,y));
		else work(a[x],x,-1),work(a[x]=y,x,1);
	}
}