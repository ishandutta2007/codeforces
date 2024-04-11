#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
//
//
const int N=100005;

int t[N],n;
void change(int x,int v){
	for (;x<=n;x+=x&(-x)) t[x]+=v; 
}
int ask(int x){
	int ans=0;
	for (;x;x-=x&(-x)) ans+=t[x];
	return ans;
} 
int erase(int x){
	int l=1,r=n,ans=n+1;
	while (l<=r){
		int mid=(l+r)/2;
		if (ask(mid)>x)
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	change(ans,-1);
	return ans-1;
}

int T[N],ed[N];
ll sum[N];
pll check(int p,int k,int x){
	x+=T[p]-k;
	int id=upper_bound(T,T+n,x)-T;
	return pll(1ll*x*id-sum[id],id);
}
int Qblock(int x,int k){
	int l=1,r=n-1,ans=0;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid,k,0).fi<=x)
			ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int Qat(int x,int k,int be){
	int l=1,r=T[be+1]-T[be],ans=0;
	if (be==n-1) r=x/n+k+1;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(be,k,mid).fi<=x)
			ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}

const int M=3000005;
int nd,sz[M],ls[M],rs[M],rt[N];
void change(int &nk,int k,int l,int r,int p){
	nk=++nd; sz[nk]=sz[k]+1;
	ls[nk]=ls[k]; rs[nk]=rs[k];
	if (l==r) return;
	int mid=(l+r)/2;
	if (p<=mid) change(ls[nk],ls[k],l,mid,p);
	else change(rs[nk],rs[k],mid+1,r,p);
}
int findkth(int k,int l,int r,int rk){
	if (l==r) return l;
	int mid=(l+r)/2;
	if (rk<sz[ls[k]]) return findkth(ls[k],l,mid,rk);
	return findkth(rs[k],mid+1,r,rk-sz[ls[k]]);
}
int asksum(int k,int l,int r,int p){
	if (r==p||!k) return sz[k];
	int mid=(l+r)/2;
	if (p<=mid) return asksum(ls[k],l,mid,p);
	return asksum(rs[k],mid+1,r,p)+sz[ls[k]];
}

int Q,a[N],id[N];
int main(){
	scanf("%d%d",&n,&Q);
	For(i,0,n-1) scanf("%d",&a[i]);
	int st=a[0];
	For(i,0,n-1) a[i]-=st;
	For(i,1,n-1){
		T[i]=T[i-1]+(a[i]-ed[i-1])/i;
		ed[i]=ed[i-1]+(a[i]-ed[i-1])/i*i;
		sum[i+1]=sum[i]+T[i]; 
	}
	For(i,1,n) change(i,1);
	Rep(i,n-1,0) id[i]=erase(a[i]-ed[i]);
	For(i,0,n-1) change(rt[i+1],rt[i],0,n-1,id[i]);
	while (Q--){
		int x,k;
		scanf("%d%d",&x,&k);
		if (x<st){
			printf("%d\n",x);
			continue;
		}
		x-=st;
		int be=Qblock(x,k);
		int at=Qat(x,k,be);
		pll res=check(be,k,at);
		int rest=x-res.fi,pre=res.se;
		int rank=findkth(rt[pre],0,n-1,rest);
		int count=(rank?asksum(rt[be+1],0,n-1,rank-1):0);
		printf("%lld\n",st+ed[be]+1ll*at*(be+1)+count);
	}
}
//ed[i]:T[i]1
//T[i]:1
//id[i]:id