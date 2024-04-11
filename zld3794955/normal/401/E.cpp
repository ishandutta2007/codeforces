#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<cstring>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<string>
#include<utility>
#include<cassert>
using namespace std;
const int N=100100,T=30;
long long n,m,l,r,mod,ans=0;
int min_prime[N]={},prime[N]={},prime_tot=0;
int p[T]={},totp=0;
void get_prime()
{
	bool d[N]={};
	long long maxn=max(n,m);
	for(int i=2;i<=maxn;++i)
	{
		if(!d[i])
			prime[++prime_tot]=i,min_prime[i]=i;
		for(int j=1;j<=prime_tot && i*prime[j]<=maxn;++j)
		{
			d[i*prime[j]]=true;
			min_prime[i*prime[j]]=prime[j];
			if(i%prime[j]==0)
				break;
		}
	}
}
void fact(int x)
{
	totp=0;
	while(x!=1)
	{
		if(min_prime[x]!=p[totp])
			p[++totp]=min_prime[x];
		x/=min_prime[x];
	}
	assert(totp<T);
}
long long get_sum(int d,long long now,long long up)
{
	if(d>totp)
	{
		long long s=m-now+1,a=up/now,t=s-(a-1)*now;
		return ((s+t)*a/2)%mod;
	}
	else
		return (get_sum(d+1,now,up)-get_sum(d+1,now*p[d],up)+mod)%mod;
}
long long get_sup(long long sup_sqr)
{
	long long l=0,r=m;
	while(l!=r)
	{
		long long mid=(l+r+1)>>1;
		if(mid*mid>sup_sqr)
			r=mid-1;
		else
			l=mid;
	}
	return l;
}
void work()
{
	if(l<=1 && 1<=r)
		ans+=(n*(m+1)+m*(n+1))%mod;
	//cout<<"ans="<<ans<<endl;
	for(long long i=1;i<=n;++i)
	{
		long long inc_sup=get_sup(r*r-i*i);
		long long dec_sup=get_sup(l*l-i*i);
		if(dec_sup && dec_sup*dec_sup==l*l-i*i)
			--dec_sup;
		//cout<<"i="<<i<<" inc_sup="<<inc_sup<<" dec_sup="<<dec_sup<<endl;
		if(inc_sup<=dec_sup)
			continue;
		fact(i);
		long long inc_sum=get_sum(1,1,inc_sup);
		long long dec_sum=get_sum(1,1,dec_sup);
		(ans+=(n-i+1)*(inc_sum-dec_sum+mod)*2%mod)%=mod;
	}
	cout<<ans<<endl;
}
int main()
{
	cin>>n>>m>>l>>r>>mod;
	get_prime();
	work();
	return 0;
}