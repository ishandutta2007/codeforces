#include<bits/stdc++.h>
using namespace std;
#define re register ll
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
#define I inline void
#define IN inline ll
typedef long long ll;
#define all 1,1,n
#define lt k<<1,l,mid
#define rt k<<1|1,mid+1,r
const ll INF=1e18+7;
ll n,m,a[202000],tr[808000],laz[808000],ans[202000],X,Y,K;
IN min(ll x,ll y){
	return x<y?x:y;
}
I build(ll k,ll l,ll r){
	if(l==r){
		tr[k]=a[l];
		return;
	}
	re mid=(l+r)>>1;
	build(lt);
	build(rt);
	tr[k]=min(tr[k<<1],tr[k<<1|1]);
}
I push_down(int k){
	tr[k<<1]-=laz[k];
	tr[k<<1|1]-=laz[k];
	laz[k<<1]+=laz[k];
	laz[k<<1|1]+=laz[k];
	laz[k]=0;
}
I modify(int k,int l,int r){
	if(l==X&&r==X){
		tr[k]=INF;
		return;
	}
	if(laz[k])push_down(k);
	re mid=(l+r)>>1;
	if(X<=mid)modify(lt);
	else modify(rt);
	tr[k]=min(tr[k<<1],tr[k<<1|1]);
}
I modi(int k,int l,int r,int x,int y,int w){
	if(x>r||y<l)return;
	if(x<=l&&r<=y){
		tr[k]-=w;
		laz[k]+=w;
		return;
	}
	if(laz[k])push_down(k);
	re mid=(l+r)>>1;
	modi(lt,x,y,w);
	modi(rt,x,y,w);
	tr[k]=min(tr[k<<1],tr[k<<1|1]);
}
int main(){
	cin>>n;
	F(i,1,n){
		cin>>a[i];
	}
	build(all);
	F(i,1,n){
		X=1;Y=n;K=1;
		while(X!=Y){
			m=(X+Y)>>1;
			if(laz[K])push_down(K);
			if(!tr[K<<1|1])K=(K<<1|1),X=m+1;
			else K<<=1,Y=m;
		}
		ans[X]=i;modify(all);
		if(X!=n)modi(all,X+1,n,i);
	}
	F(i,1,n){
		cout<<ans[i]<<" ";
	}
    return 0;
}