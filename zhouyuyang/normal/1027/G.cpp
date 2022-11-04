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
#define EB emplace_back
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

#define INF ((1<<30)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;
const ll mo=100000000000031ll;
ll m,x,pri[50],ans;
int cnt[50];
ll divide(ll &a,ll b,bool fl){
	if (b<2||a%b) return 1;
	ll ans=b-1; if (fl==0) cnt[++(*cnt)]=1;
	for (a/=b;a%b==0;a/=b)
		if (fl==1) ans*=b;
		else cnt[*cnt]++;
	if (fl==0) pri[*cnt]=b;
	return ans;
}
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
ll mul(ll x,ll y,ll mod){
	ll ans=0;
	for (;y;y>>=16){
		ans=(ans+x*(y&65535))%mod;
		x=(x<<16)%mod;
	}
	return ans;
}
ll power(ll x,ll y,ll mod){
	ll ans=1;
	for (;y;y/=2,x=mul(x,x,mod))
		if (y&1) ans=mul(ans,x,mod);
	return ans;
}
void dfs(int id,ll a,ll divi,ll phi){
	if (id>*cnt){
		ans=(ans+mul(gcd(m,power(x,a/divi,m)-1),phi,mo))%mo;
		return;
	}
	for (int j=0;j<=cnt[id];j++)
		dfs(id+1,a,divi,phi),divi*=pri[id],phi*=pri[id]-(!j);
}
int main(){
	scanf("%lld%lld",&m,&x);
	ll a=m,b=divide(a,2,1)*divide(a,3,1);
	for (int i=5;1ll*i*i<=a;i+=6)
		b*=divide(a,i,1)*divide(a,i+2,1);
	b*=divide(a,a,1);
	a=b; divide(b,2,0); divide(b,3,0);
	for (int i=5;1ll*i*i<=b;i+=6)
		divide(b,i,0),divide(b,i+2,0);
	divide(b,b,0);
	dfs(1,a,1,1);
	ans=mul(ans,power(a,mo-2,mo),mo);
	printf("%lld\n",ans);
}