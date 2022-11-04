#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define vi vector<int>
#define vpi vector<pii >
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define y1 wzpakking 
#define fi first
#define se second
#define BG begin
#define ED end
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
#define INF (1<<29)
using namespace std;
ll n,l,r,k,ans=-1;
void checkok(ll val2,ll val1,ll fi,ll se,ll pre){
	val2=val2-val1;
	se=se-fi;
	if (!(fi+pre<=val1&&val1<=2*fi)) return;
	if (!(se<=val2&&val2<=2*se)) return;
	ans=max(ans,val1+val2-fi-se);
}
void check1(ll val){
	checkok(val,(k+val-1)%val+1,r,n,0);
	checkok(val,k%val+1,r,n,1);
}
pll getrange(ll lv,ll k,ll mv,ll rv){
	lv-=mv; rv-=mv;
	if (!k){
		if (lv<=0&&rv>=0) return pll(0,1ll<<60);
		return pll(-1,-1);
	}
	if (k<0){
		swap(lv,rv);
		lv=-lv; rv=-rv;
		k=-k;
	}
	if (rv<0) return pll(-1,-1);
	if (lv<0) lv=max(lv,0ll);
	return pll((lv+k-1)/k,rv/k);
}
pll merge(pll a,pll b){
	if (a.fi==-1||b.fi==-1) return pll(-1,-1);
	if (a.se>b.se) swap(a,b);
	if (a.se<b.fi) return pll(-1,-1);
	return pll(max(a.fi,b.fi),a.se);
}
void check2(ll round){
	if (round==0){
		if (r<=k&&k<=2*r) ans=max(ans,n-r+k-r);
		if (r+1<=k+1&&k+1<=2*r) ans=max(ans,n-r+(k+1-r));
		return;
	}
	ll r=min(k/round,2*n);
	ll l=max(k/(round+1)+1,n);
	ll fi=::r,se=n-::r;
	if (l<=r){
		pll range1=getrange(fi+1,-round,k+1,2*fi);
		pll range2=getrange(se,round+1,-k-1,2*se);
		pll range=merge(pll(l,r),merge(range1,range2));
		if (range.fi!=-1) ans=max(ans,range.se-n);
	}
	r=min((k-1)/round,2*n);
	l=max((k-1)/(round+1)+1,n);
	if (l<=r){
		pll range1=getrange(fi,-round,k,2*fi);
		pll range2=getrange(se,round+1,-k,2*se);
		pll range=merge(pll(l,r),merge(range1,range2));
		if (range.fi!=-1) ans=max(ans,range.se-n);
	}
}
//checkok(val,k-round*val+1,r,n,1)
//val2=(round+1)*val-k-1 
//val1=k-round*val+1
//fi+1<=round<=2*fi

//checkok(val,k-round*val,r,n,1)
//val2=(round+1)*val-k
//val1=k-round*val
//fi<=round<=2*fi
int main(){
	scanf("%lld%lld%lld%lld",&n,&l,&r,&k);
	r=(r-l+n)%n+1;
	if (n<=200000)
		for (ll i=n;i<=2*n;i++) check1(i);
	else
		for (ll round=k/(2*n);round<=k/n;round++)
			check2(round);
	printf("%lld",ans);
}