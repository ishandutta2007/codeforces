#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int>P;
mt19937_64 R(114514);
const int N=1e5+5;
namespace NT{
inline ll mul(ll x,ll y,const ll&mo){ll ass=0;for(;y;y>>=10,x=(x<<10)%mo)ass=(ass+(y&1023)*x)%mo;return ass;}
inline ll poww(ll x,ll y,const ll&mo){ll ass=1;for(;y;y>>=1,x=mul(x,x,mo))if(y&1)ass=mul(ass,x,mo);return ass;}
inline bool MR(ll x){
	static int pr[]={2,3,5,7,11,13,17,19,23,29,31,37};
	for(int v:pr)if(v<x && x%v==0)return 0;if(x<=999)return 1;
	for(int v:pr)if(poww(v,x-1,x)!=1)return 0;
	for(int i=0;i<10;++i){ll v=R()%x;if(v && poww(v,x-1,x)!=1)return 0;}
	return 1;
}
inline ll findd(ll n){
	if(n<10)for(int i=2;;++i)if(n%i==0)return i;
	ll x,y,a,g;auto F=[&](ll x){return (mul(x,x,n)+a)%n;};
	for(;;)for(a=R()%n,y=x=R()%n;x=F(x),y=F(F(y)),x!=y;)if(g=__gcd(abs(x-y),n),1<g && g<n)return g;
}
inline vector<ll>fac(ll n){
	if(n==1)return {};
	vector<ll>ret;queue<ll>q;
	auto ins=[&](ll n){if(MR(n))ret.push_back(n);else q.push(n);};
	for(ins(n);!q.empty();){ll x=q.front(),y=findd(x);q.pop();ins(y);ins(x/y);}
	return ret;
}
}
struct solver{
	ll n;
	vector<ll>fac;
	ll d[N];
	void SSSP(){
		priority_queue<P,vector<P>,greater<P>>q;ll y,ny,f1[19];int i,x,nx,f2[19],fs=fac.size(),f0=fac[0];
		for(i=0;i<fac[0];++i)d[i]=i?1ll<<60:0;q.push({0,0});
		for(i=1;i<fs;++i)f1[i]=fac[i]/f0,f2[i]=fac[i]%f0;
		for(;!q.empty();){
			tie(y,x)=q.top();q.pop();if(y>d[x])continue;
			for(i=1;i<fs;++i){
				ny=y+f1[i];nx=x+f2[i];nx>=f0?++ny,nx-=f0:0;
				if(d[nx]>ny)q.push({d[nx]=ny,nx});
			}
		}
	}
	void ini(ll nn){
		n=nn;
		fac=NT::fac(n);
		sort(fac.begin(),fac.end());fac.erase(unique(fac.begin(),fac.end()),fac.end());
		if(fac.size()<3)return;
		SSSP();
	}
	bool ask(ll k){
		if(fac.empty())return 0;
		if(fac.size()==1)return k%fac[0]==0;
		if(fac.size()>=3)return d[k%fac[0]]<=k/fac[0];
		function<void(ll,ll,ll&,ll&)>exgcd=[&](ll a,ll b,ll&x,ll&y){
			if(b)exgcd(b,a%b,y,x),y-=a/b*x;else x=k%fac[0],y=0;
		};
		ll a=fac[0],b=fac[1],x,y,z;
		if(k>a*b-a-b)return 1;
		exgcd(a,b,x,y);x+=k/a;
		if(x<0)z=(-x+b-1)/b,x+=z*b,y-=z*a;if(y<0)z=(-y+a-1)/a,y+=z*a,x-=z*b;
		return x>=0 && y>=0;
	}
};
map<ll,solver>mp;
int T;
ll n,k;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%lld%lld",&n,&k);
		if(!mp.count(k))mp[k].ini(k);
		puts(mp[k].ask(n)?"YES":"NO");
	}
	return 0;
}