#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,a[N],i,j,k,p,c[N];
ll l,r,m,rk,s1[N],s2[N];
void inig(){
	vector<pair<int,int>>ve1,ve2;
	for(i=n;i;--i){
		ve2={{i,a[i]}};
		for(auto u:ve1){
			int x,y;tie(x,y)=u;
			y=__gcd(y,a[i]);
			if(ve2.back().second>y)ve2.push_back({x,y});
		}
		ve1=ve2;
		for(j=0;j<ve1.size();++j)c[ve1[j].second]+=(j+1==ve1.size()?n+1:ve1[j+1].first)-ve1[j].first;
	}
}
ll sgcd(ll a,ll b,ll c,ll lx){
	if(a==0)return (c/b+1)*(lx+1);
	ll ret=0;
	if(a*lx+b<=c){
		ll d=(c-a*lx)/b;
		ret+=d*(lx+1);
		c-=d*b;
	}
	if((lx+1)*a<=c)ret-=(c-lx*a)/a;
	if(a>=b){
		ll q=a/b,r=a%b;
		ret+=sgcd(r,b,c,c/a)-q*(c/a+1)*(c/a)/2;
	}else ret+=sgcd(b,a,c,c/b);
	return ret;
}
ll calcc(int a,int b,ll c,int x0,int y0){
	ll ans=0;
	for(int i=1;i<=x0;++i)for(int j=1;j<=y0;++j)ans+=1ll*a*i+1ll*b*j<=c;
	return ans;
}
ll calc(int a,int b,ll c,int x0,int y0){
	if(a+b>c)return 0;
	if(1ll*a*x0+1ll*b*y0<=c)return 1ll*a*b;
	ll ans=0;
	--x0;--y0;c-=a+b;
	if(1ll*y0*b+a<=c){
		ll d=(c-1ll*y0*b)/a;
		ans+=d*(y0+1);x0-=d;c-=d*a;
	}
	if(1ll*x0*a+b<=c){
		ll d=(c-1ll*x0*a)/b;
		ans+=d*(x0+1);y0-=d;c-=d*b;
	}
	ans-=max(0ll,c/b-y0);ans-=max(0ll,c/a-x0);
	ans+=sgcd(a,b,c,c/a);
	return ans;
}
ll calc(ll v){
	ll ans=0;
	for(i=1;i<N;++i)if(c[i]){
		ll l=min(v/i,ll(c[i]));
		ans+=l*(c[i]+1)-l*(l+1)/2;
	}
	for(i=2,j=k=1;i<N;++i)if(c[i]){
		for(;j+1<i && (!c[j] || s2[i-1]-s2[j]+i+j>v);++j);
		for(;k<i && s2[i]-s2[k-1]>v;++k);
		ans+=1ll*c[i]*(s1[i-1]-s1[k-1]);
		for(p=j;p<k;++p)if(c[p])
			ans+=calc(p,i,v-(s2[i-1]-s2[p]),c[p],c[i]);
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;for(i=1;i<=n;++i)cin>>a[i];
	inig();for(i=1;i<N;++i)s1[i]=s1[i-1]+c[i],s2[i]=s2[i-1]+1ll*i*c[i];
	l=1ll*n*(n+1)/2;rk=(1ll*l*(l+1)/2+1)/2;
	l=0;r=1e15;
	for(;l<r;){
		m=l+r>>1;
		if(calc(m)>=rk)r=m;else l=m+1;
	}
	cout<<l<<endl;
	return 0;
}