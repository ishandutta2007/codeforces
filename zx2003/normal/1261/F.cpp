#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105,mo=998244353;
struct range{
ll l,d;bool tp;
inline void go(ll x){if(d>x)d-=x,tp==0?l+=x:l-=x;}
}A[N],B[N],C[N],D[N];
pair<ll,int>a[6000000];int xb;
int na,nb,i,j,x,ans;
ll la[N],ra[N],lb[N],rb[N],ma[N],mb[N];
inline void in(int&n,range*a,range*b){
	scanf("%d",&n);
	for(i=0;i<n;++i){
		ll l,r,m;
		scanf("%lld%lld",&l,&r);
		for(m=l;m+(m&-m)<=r;m+=m&-m);
		a[i]=(range){m-1,m-l,1};b[i]=(range){m,r-m+1,0};
	}
}
inline void add(ll l,ll d){a[++xb]={l,1};a[++xb]={l+d,-1};}
inline void work(range a,range b){
	ll x=1ll<<60;
	for(;x;x>>=1){
		bool fa=a.d>x,fb=b.d>x;
		if(!fa && !fb)continue;
		if(fa && fb)return add((a.l^b.l)&~(x*2-1),x*2);
		if(fa^fb)add((a.l^b.l)&~(x-1),x);
		a.go(x);b.go(x);
	}
	add(a.l^b.l,1);
}
int main(){
	in(na,A,B);in(nb,C,D);
	for(i=0;i<na;++i)for(j=0;j<nb;++j){
		if(A[i].d && C[j].d)work(A[i],C[j]);
		if(A[i].d && D[j].d)work(A[i],D[j]);
		if(B[i].d && C[j].d)work(B[i],C[j]);
		if(B[i].d && D[j].d)work(B[i],D[j]);
	}
	sort(a+1,a+xb+1);
	for(i=1;i<=xb;i=j){
		for(j=i;j<=xb && a[j].first==a[i].first;x+=a[j++].second);
		if(x)ans=(ans+(a[i].first+a[j].first-1)%mo*((a[j].first-a[i].first)%mo))%mo;
	}
	ans&1?ans+=mo:0;ans>>=1;
	printf("%d\n",ans);
	return 0;
}