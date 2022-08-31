#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
#define SIZE 100005
#define MX 100000000000000000LL

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct gausssum
{
	ll md(ll x,ll y)
	{
		if(x>=0) return x/y;
		ll vl=md(-x,y);
		if((-x)%y==0) return -vl;
		return -vl-1;
	}
	ll count(ll s,ll t,ll n,ll a,ll b)//[(ax+b)/n](s<=x<=t)
	{
		if(a<0)
		{
			//printf("* %lld %lld %lld %lld %lld : %lld\n",s,t,n,a,b,count(-t,-s,n,-a,b));
			return count(-t,-s,n,-a,b);
		}
		ll S=md(a*s+b,n),T=md(a*t+b,n);
		if(S==T)
		{
			return (t-s+1)*S;
		}
		if(n<=a)
		{
			ll sum=(s+t)*(t-s+1)/2LL;
			return count(s,t,n,a%n,b)+sum*(a/n);
		}
		ll sum=count(S+1,T,a,n,-b-1);
		ll all=T*t-S*(s-1);
		//printf("* %lld %lld %lld %lld %lld : %lld\n",s,t,n,a,b,all-sum);
		return all-sum;
	}
}gauss;
int A[SIZE];
ll cnt[SIZE],rt[SIZE],rt2[SIZE];
P st[SIZE],cmp[SIZE];

int gcd(int x,int y)
{
	if(x==0) return y;
	return gcd(y%x,x);
}
ll solve(ll D,ll s,ll e)
{
	D-=rt[e-1]-rt[s];
	if(D<0) return 0;
	//ll X=D;
	ll ret=0;
	ll a=cnt[s],b=cnt[e];
	if(a==0||b==0) return 0;
	if(e*b<=D)
	{
		ll c=min((D-e*b)/s,a);
		ret+=b*c;
		a-=c;
		D-=c*s;
	}
	if(a==0) return ret;
	//printf("%lld %lld %lld : %lld %lld : %lld\n",D,s,e,a,b,gauss.count(1,min(a,D/a),e,-s,D));
	//printf("%lld %lld %lld : %lld %lld : %lld\n",X,s,e,cnt[s],cnt[e],ret+gauss.count(1,min(a,D/a),e,-s,D));
	return ret+gauss.count(1,min(a,D/s),e,-s,D);
}
ll getcnt(ll D)
{
	ll sum=0,ret=0;
	for(int i=1;i<SIZE;i++)
	{
		ll mn=min(cnt[i],D/i);
		ret+=(ll) (2LL*cnt[i]-mn+1)*(ll) mn/2LL;
	}
	//printf("*%lld\n",ret);
	int to=1;
	for(int i=1;i<SIZE;i++)
	{
		while(to<SIZE&&sum+(ll) cnt[to]*(ll) to<D)
		{
			if(1<i) ret+=solve(D,i-1,to);
			sum+=(ll) cnt[to]*(ll) to;
			to++;
		}
		if(1<i&&to<SIZE) ret+=solve(D,i-1,to);
		if(to==i)
		{
			sum=0;
			to=i+1;
		}
		else
		{
			ret+=cnt[i]*(rt2[to-1]-rt2[i]);
			sum-=(ll) cnt[i]*(ll) i;
		}
	}
	return ret;
}
ll getcnt_naive(ll D)
{
	ll ret=0;
	vector <ll> vec;
	for(int i=1;i<SIZE;i++) for(int j=0;j<cnt[i];j++) vec.push_back(i);
	int to=0;
	ll sum=0;
	for(int i=0;i<vec.size();i++)
	{
		while(to<vec.size()&&sum+vec[to]<=D) sum+=vec[to++];
		ret+=to-i;
		if(to==i)
		{
			to=i+1;
			sum=0;
		}
		else sum-=vec[i];
	}
	return ret;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);/*
	if(true)
	{
		n=7;
		for(int i=0;i<n;i++) A[i]=rand()%10+1;
		for(int i=0;i<n;i++) printf("%d ",A[i]);puts("");
	}*/
	int sz=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<sz;j++) st[j].first=gcd(st[j].first,A[i]);
		st[sz++]=P(A[i],1);
		int ns=0;
		for(int j=0;j<sz;)
		{
			int f=st[j].first,c=0;
			for(;j<sz&&st[j].first==f;j++) c+=st[j].second;
			cmp[ns++]=P(f,c);
		}
		sz=ns;
		for(int j=0;j<sz;j++)
		{
			st[j]=cmp[j];
			cnt[st[j].first]+=st[j].second;
		}
	}
	for(int i=1;i<SIZE;i++)
	{
		rt[i]=(ll) i*(ll) cnt[i];
		rt[i]+=rt[i-1];
		rt2[i]=cnt[i];
		rt2[i]+=rt2[i-1];
	}
	//for(int i=1;i<=10;i++) if(cnt[i]!=0) printf("[%d %lld] ",i,cnt[i]);puts("");
	//printf("%lld %lld\n",getcnt(19),getcnt_naive(19));
	//return 0;
	ll L=(ll) n*(ll) (n+1)/2LL;
	ll all=L*(L+1)/2LL;
	//printf("%lld\n",(all+1)/2);
	ll l=0,r=MX;
	while(r-l>1)
	{
		ll d=(l+r)/2;
		if(getcnt(d)<(all+1)/2) l=d;
		else r=d;
		//printf("%lld %lld\n",d,getcnt(d));
	}
	printf("%lld\n",r);
	/*
	
	l=0,r=MX;
	while(r-l>1)
	{
		ll d=(l+r)/2;
		if(getcnt_naive(d)<(all+1)/2) l=d;
		else r=d;
		//printf("%lld %lld\n",d,getcnt(d));
	}
	printf("%lld\n",r);*/
	return 0;
}