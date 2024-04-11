#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db long double
#define pii pair<int,int>
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

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define inf ((1<<30)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;
const int mo=1000000007;
const int N=200005;
int n,q;
int a[N],w[N];
ll cntw[N*4];
int val[N*4];
void build(int k,int l,int r){
	if (l==r){
		cntw[k]=w[l];
		val[k]=1ll*w[l]*a[l]%mo;
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	cntw[k]=cntw[k*2]+cntw[k*2+1];
	val[k]=(val[k*2]+val[k*2+1])%mo;
}
void change(int k,int l,int r,int p,int v){
	if (l==r){
		cntw[k]=v;
		val[k]=1ll*v*a[l]%mo;
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid) change(k*2,l,mid,p,v);
	else change(k*2+1,mid+1,r,p,v);
	cntw[k]=cntw[k*2]+cntw[k*2+1];
	val[k]=(val[k*2]+val[k*2+1])%mo;
}
ll askw(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return cntw[k];
	int mid=(l+r)/2;
	if (y<=mid) return askw(k*2,l,mid,x,y);
	if (x>mid) return askw(k*2+1,mid+1,r,x,y);
	return askw(k*2,l,mid,x,mid)+askw(k*2+1,mid+1,r,mid+1,y);
}
int findpos(int k,int l,int r,ll v){
	if (l==r) return l;
	int mid=(l+r)/2;
	if (cntw[k*2]<=v)
		return findpos(k*2+1,mid+1,r,v-cntw[k*2]);
	return findpos(k*2,l,mid,v);
}
int askcnt(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return val[k];
	int mid=(l+r)/2;
	if (y<=mid) return askcnt(k*2,l,mid,x,y);
	if (x>mid) return askcnt(k*2+1,mid+1,r,x,y);
	return (askcnt(k*2,l,mid,x,mid)+askcnt(k*2+1,mid+1,r,mid+1,y))%mo;
}
int calc(int l,int mid,int r){
	int ans=0;
	if (mid>=l){
		ans=mo-askcnt(1,1,n,l,mid);
		ans=(ans+1ll*askw(1,1,n,l,mid)%mo*a[mid]%mo)%mo;
	}
	if (mid<r){
		ans=(ans+askcnt(1,1,n,mid+1,r))%mo;
		ans=(ans+mo-1ll*askw(1,1,n,mid+1,r)%mo*a[mid]%mo)%mo;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]+=n-i;
	for (int i=1;i<=n;i++) scanf("%d",&w[i]);
	build(1,1,n);
	while (q--){
		int x,y;
		scanf("%d%d",&x,&y);
		if (x<0) change(1,1,n,-x,y);
		else{
			ll sum=askw(1,1,n,x,y);
			ll leftv=(sum+1)/2; 
			if (x!=1)
				leftv+=askw(1,1,n,1,x-1);
			int mid=findpos(1,1,n,leftv-1);
			printf("%d\n",calc(x,mid,y));
		}
	}
}