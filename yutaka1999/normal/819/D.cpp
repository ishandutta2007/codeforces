#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005

using namespace std;
typedef long long int ll;
typedef pair <ll,int> P;

ll A[SIZE];
ll ans[SIZE];

ll gcd(ll x,ll y)
{
	if(x==0) return y;
	return gcd(y%x,x);
}
ll euler(ll n)
{
	ll ret=n;
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			ret/=i;
			ret*=(ll) (i-1);
			while(n%i==0) n/=i;
		}
	}
	if(n!=1)
	{
		ret/=n;
		ret*=(ll) (n-1);
	}
	return ret;
}
ll mpow(ll m,ll t,ll mod)
{
	if(t==0) return 1LL;
	ll ret=mpow(m*m%mod,t/2,mod);
	if(t%2==1) ret=ret*m%mod;
	return ret;
}
void solve(vector <P> vec,ll T,ll K)//(T,K)=1
{
	ll inv=mpow(K%T,euler(T)-1,T);
	vector <P> vx;
	for(int i=0;i<vec.size();i++)
	{
		P p=vec[i];
		p.first=p.first%T*inv%T;
		vx.push_back(p);
	}
	sort(vx.begin(),vx.end());/*
	for(int i=0;i<vx.size();i++)
	{
		P p=vx[i];
		printf("%lld %d\n",p.first,p.second);
	}*/
	for(int i=0;i<vx.size();)
	{
		int f=i;
		for(;i<vx.size()&&vx[f].first==vx[i].first;i++)
		{
			int v=vx[i].second;
			ans[v]=0;
		}
		ll nxt;
		if(i<vx.size()) nxt=vx[i].first;
		else nxt=vx[0].first+T;
		ans[vx[f].second]=nxt-vx[f].first;
	}
}
int main()
{
	ll T;
	int n;
	scanf("%lld %d",&T,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&A[i]);
		if(i>0) A[i]+=A[i-1];
	}
	ll K=A[n-1];
	ll g=gcd(T,K);
	vector <P> vx;
	for(int i=0;i<n;i++) vx.push_back(P(A[i]%g,i));
	sort(vx.begin(),vx.end());
	for(int i=0;i<n;)
	{
		vector <P> vec;
		int f=i;
		for(;i<n&&vx[f].first==vx[i].first;i++)
		{
			int v=vx[i].second;
			vec.push_back(P(A[v]/g,v));
		}
		solve(vec,T/g,K/g);
	}
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		printf("%lld",ans[i]);
	}puts("");
	return 0;
}