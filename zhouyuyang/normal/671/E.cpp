#include<bits/stdc++.h>
#define For(i,j,k) for (int i=j;i<=k;i++)
#define DN if(tg[k])ADD(k*2,tg[k]),ADD(k*2+1,tg[k]),tg[k]=0
#define GET DN;int mid=(l+r)/2
#define ADD(k,x) a[k]+=x,c[k]+=x,tg[k]+=x
#define UP a[k]=max(a[k*2],a[k*2+1]),c[k]=calc(k*2+1,mid+1,r,a[k*2])
#define inf (1ll<<61)
#define ll long long
using namespace std;
const int N=100005,M=265000;
ll a[M],b[M],c[M],tg[M];
ll w[N],g[N],s1[N],s2[N];
int q[N],n,ans,lim;
ll calc(int k,int l,int r,ll x){
	if (l==r) return x-b[k]; GET;
	if (x>a[k*2]) return min(x-b[k*2],calc(k*2+1,mid+1,r,x));
	return min(c[k],calc(k*2,l,mid,x));
}
void build(int k,int l,int r){
	if (l==r) return a[k]=b[k]=s2[l],void(0); GET;
	build(k*2,l,mid); build(k*2+1,mid+1,r);
	UP; b[k]=max(b[k*2],b[k*2+1]);
}
void add(int k,int l,int r,int x,int y,ll v){
	if (l==x&&r==y) return ADD(k,v),void(0); GET;
	if (y<=mid) add(k*2,l,mid,x,y,v);
	else if (x>mid) add(k*2+1,mid+1,r,x,y,v);
	else add(k*2,l,mid,x,mid,v),add(k*2+1,mid+1,r,mid+1,y,v); UP; 
}
ll solve(int k,int l,int r,ll x){
	if (l==r) return x-b[k]>lim?0:l; GET;
	if (x-b[k*2+1]<=lim) return solve(k*2+1,mid+1,r,x);
	return solve(k*2,l,mid,x);
}
int ask(int k,int l,int r,ll x){
	if (l==r) return x-b[k]>lim?0:l; GET; int ans=0;
	if (x>a[k*2]) ans=solve(k*2,l,mid,x);
	else if (c[k]>lim) return ask(k*2,l,mid,x);
	return max(ans,ask(k*2+1,mid+1,r,max(x,a[k*2]))); 
}
int h[N];
vector<int> e[N];
void solve(int x){
	h[++*h]=x;
	int l=1,r=*h,pos=n;
	while (l<=r){
		int mid=(l+r)/2;
		if (s1[x]-s1[h[mid]]>lim)
			pos=h[mid]-1,l=mid+1;
		else r=mid-1;
	}
	if (x-1) add(1,1,n,1,x-1,-inf);
	add(1,1,n,pos,n,inf);
	ans=max(ans,ask(1,1,n,-inf)-x+1);
	add(1,1,n,pos,n,-inf);
	if (x-1) add(1,1,n,1,x-1,inf);
	for (int i=0;i<e[x].size();i++){
		if (x>1) add(1,1,n,x-1,n,s1[e[x][i]]-s1[x]);
		solve(e[x][i]);
		if (x>1) add(1,1,n,x-1,n,s1[x]-s1[e[x][i]]);
	} 
	--*h;
}
int main(){
	scanf("%d%d",&n,&lim);
	For(i,1,n-1) scanf("%lld",&w[i]);
	For(i,1,n) scanf("%lld",&g[i]);
	For(i,1,n-1){
		s1[i+1]=s1[i]+g[i]-w[i];
		s2[i+1]=s2[i]+g[i+1]-w[i];
	}
	build(1,1,n);
	int t=0;
	For(i,1,n){
		for (;t&&s1[i]<s1[q[t]];)
			e[i].push_back(q[t--]);
		q[++t]=i;
	}
	For(i,1,t) solve(q[i]);
	printf("%d\n",ans);
}