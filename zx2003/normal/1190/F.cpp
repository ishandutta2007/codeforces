#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937_64 R(time(0));
int n;
ll phi,mo,b,p;
vector<ll>ans;
void push(ll x){
	ans.push_back(x);
	if(ans.size()==n){for(ll x:ans)printf("%lld ",x);puts("");exit(0);}
}
inline ll mul(ll a,ll b,const ll&mo){ll ass=0;for(;b;b>>=3,a=(a<<3)%mo)ass=(ass+(b&7)*a)%mo;return ass;}
inline ll poww(ll a,ll b,const ll&mo){ll ass=1;for(;b;b>>=1,a=mul(a,a,mo))if(b&1)ass=mul(ass,a,mo);return ass;}
namespace NT{
bool MR(ll x){
	static int pr[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
	for(int u:pr){if(x==u)return 1;if(x%u==0)return 0;}
	for(int i=0;i<10;++i){ll v=R()%x;if(v && poww(v,x-1,x)!=1)return 0;}
	return 1;
}
ll findd(ll n){
	if(n<10){for(int i=2;i<n;++i)if(n%i==0)return i;return -114514;}
	ll a=R()%n,x=R()%n,y=x;
	auto F=[&](const ll&x){return (mul(x,x,n)+a)%n;};
	for(;;){
		x=F(x);y=F(F(y));
		if(x==y)break;
		ll g=__gcd(n,abs(x-y));
		if(1<g && g<n)return g;
	}
	return findd(n);
}
vector<ll>fac;
void init_factor(ll x){
	unordered_map<ll,int>mp;queue<ll>q;
	for(q.push(x);!q.empty();){
		ll x=q.front();q.pop();if(MR(x)){++mp[x];continue;}
		ll t=findd(x);q.push(t);q.push(x/t);
	}
	vector<pair<ll,int>>tmp;for(auto u:mp)tmp.push_back(u);fac.clear();
	function<void(int,ll)>dfs=[&](int d,ll pi){
		if(d==tmp.size())return fac.push_back(pi);
		for(int i=0;;){
			dfs(d+1,pi);
			if(++i>tmp[d].second)break;
			pi*=tmp[d].first;
		}
	};
	dfs(0,1);
	sort(fac.begin(),fac.end());
}
ll getord(ll u){
	for(ll v:fac)if(poww(u,v,mo)==1)return v;
	return -114514;
}
ll getrt(){
	ll x=1;
	for(;getord(x)!=fac.back();++x);
	return x;
}
}
namespace BF{
unordered_set<ll>S={1};
void main(){
	if(b%p==0)for(ll t=1;S.insert(t),t;t=mul(t,b,mo));
		else for(ll t=1;t=mul(t,b,mo),t!=1;S.insert(t));
	for(ll i=1;i<mo;++i)if(!S.count(i) && __gcd(i,mo)==1)S.insert(i),push(i);
}
}
namespace ODD{
void main(){
	ll g=NT::getrt(),k=phi/NT::getord(b),mi=1;
	if(k==1)return;
	for(ll i=0;!i || mi!=1;mi=mul(mi,g,mo),++i)if(i%k)push(mi);
}
}
namespace TWO{
void main(){
	ll k=phi/2/NT::getord(b%4==1?b:mo-b),mi=1;
	for(ll i=0;!i || mi!=1;mi=mul(mi,5,mo),++i)if(b%4==1){
		if(i%k)push(mi);push(mo-mi);
	}else{
		if(i%k || (i/k)%2==1)push(mi);
		if(i%k || (i/k)%2==0)push(mo-mi);
	}
}
}
int main(){
	scanf("%d%lld%lld",&n,&mo,&b);
	NT::init_factor(mo);p=NT::fac[1];phi=mo/p*(p-1);
	if(b%p==0 || mo<10 || b==1)BF::main();
		else if(NT::init_factor(mo/p*(p-1)),p&1)ODD::main();
				else TWO::main();
	puts("-1");
	return 0;
}